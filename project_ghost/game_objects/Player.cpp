//
// Created by jimte on 2020-12-03.
//

#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <vector>
#include <random>

#include "Player.h"
#include "../managers/World.h"
#include "Enemy.h"
#include "Money.h"
#include "Door.h"
#include "../managers/Sound_Manager.h"

float lerp(float const a, float const b, float const t)
{
    return ( a + (b - a) * t);
}

float flip(float const x)
{
    return 1-x;
}


Player::Player(sf::Vector2f center, Player_Info &player_info)
        : Character{center, "player_sheet.png", 100, 20},
          player_state{Player_State::falling}, off_platform{false}, drop_margin{0.0},
          vertical_duration{0.0}, horizontal_duration{0.0}, jump_start{0.0},
          inertia{false}, moved_last_update{false}, facing_right{true},
          jump_pressed{false}, jump_count{1}, max_jumps{},
          run_speed{}, player_info{player_info},
          weapon{center, "weapon.png"}, x_at_last_frame(center.x)
{
    const float SCALE{4};

    sf::Vector2f size{shape.getTexture()->getSize()};

    size = {size.x/13 * SCALE, size.y * SCALE};
    sf::IntRect texture_rect{0, 0, 28, 32};

    hitbox = size;
    shape.setTextureRect(texture_rect);
    shape.setSize(size);
    shape.setOrigin(size.x/2, size.y/2);
    shape.setPosition(center);

    const float HAT_MARGIN{90.0f};
    hitbox = {(hitbox.x - HAT_MARGIN), hitbox.y};

    apply_upgrades();
}

bool Player::update(const sf::Time &delta, World &world)
{
    move_player(delta, world);

    handle_weapon(delta, world);
    handle_collision(world);
    handle_animation();

    return still_alive();
}

void Player::handle_weapon(const sf::Time &delta, World &world)
{
    weapon.set_position(center);
    weapon.update(delta, world);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        weapon.shoot(delta, world);
    }
}

void Player::move_player(sf::Time delta, World &world)
{
    handle_horizontal_move(delta, world);

    handle_jump_input();

    handle_drop();

    if (player_state == jumping)
    {
        jump(delta);
    }
    if ( player_state == falling )
    {
        fall(delta, world);
    }
}

void Player::handle_collision(World &world)
{
    for (auto &collision : world.collides_with(*this))
    {
        if (dynamic_cast<Platform *>(collision.get()))
        {
            float player_bottom_edge{get_bottom()};
            float platform_top_edge{collision->get_top()};
            const float MARGIN {30};

            if ( player_state == 2 // falling
                && drop_margin <= 0.0
                && player_bottom_edge > platform_top_edge
                &&  player_bottom_edge < platform_top_edge + MARGIN)
            {
                player_state = standing;
                vertical_duration = 0;
                jump_start = 0;
                jump_count = max_jumps;

                set_position({center.x, platform_top_edge+1 - shape.getSize().y/2});
            }

            if (get_bottom() == collision->get_top() + 1) // player stands on top of platform
            {
                if (    get_left() + 10 > collision->get_right()
                     || get_right() - 10 < collision->get_left() ) // outside platform right or left
                {
                    off_platform = true;
                } else
                {
                    off_platform = false;
                }
            }
        }

        if (dynamic_cast<Enemy *>(collision.get()))
        {
            take_damage(dynamic_cast<Enemy *>(collision.get())->damage);
        }

        if (dynamic_cast<Money *>(collision.get()))
        {
            std::random_device rd;
            std::uniform_int_distribution<int> uniform(20,27);
            player_info.add_money(uniform(rd));
            Sound_Manager::play_sound("soul_pickup.wav");
        }
        if (dynamic_cast<Door *>(collision.get()))
        {
            take_damage(dynamic_cast<Enemy *>(collision.get())->damage);
        }
    }
    if ( player_state == 0 && off_platform ) // off_platform only sets falling state if all platforms agree
    {
        player_state = falling;
    }
}

void Player::handle_jump_input()
{
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space ) && !jump_pressed)
    {
        jump_pressed = true;
        if (jump_count > 0)
        {
            player_state = jumping;
            jump_start = center.y;
            jump_count--;
            vertical_duration = 0;
            drop_margin = 0.0;
            Sound_Manager::play_sound("jump.wav");
        }
    }
    if ( ! sf::Keyboard::isKeyPressed(sf::Keyboard::Space ) )
    {
        jump_pressed = false;
    }
}

void Player::handle_drop()
{
    const float DROP_DISTANCE{30};

    if ( player_state == 0
        && (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
    {
        drop_margin = get_bottom() + DROP_DISTANCE;
        player_state = falling;
    }
}

void Player::handle_inertia(sf::Time delta)
{
    const float INERTIA_DISTANCE{200};
    const float INERTIA_TIME_AS_SEC{0.1};

    if (   moved_last_update && !facing_right
           && ! sf::Keyboard::isKeyPressed(sf::Keyboard::A)
           && ! sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
    {
        inertia = true;
    }
    if (   moved_last_update && facing_right
           && ! sf::Keyboard::isKeyPressed(sf::Keyboard::D)
           && ! sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
    {
        inertia = true;
    }

    if ( inertia )
    {
        horizontal_duration += delta.asSeconds();

        float progress{horizontal_duration / INERTIA_TIME_AS_SEC};
        progress = flip(powf(flip(progress), 2));

        float inertia_speed{ lerp(0.0f, INERTIA_DISTANCE, progress) };
        float inertia_movement{ inertia_speed * delta.asSeconds()};
        if ( ! facing_right )
        {
            inertia_movement = -inertia_movement;
        }

        set_position({get_position().x + inertia_movement, get_position().y});
    }

    if (horizontal_duration > INERTIA_TIME_AS_SEC)
    {
        inertia = false;
        horizontal_duration = 0.0;
    }
}

void Player::handle_horizontal_move(sf::Time delta, World &world)
{
    handle_inertia(delta);
    moved_last_update = false;


    float direction{0.0f};
    if (   sf::Keyboard::isKeyPressed(sf::Keyboard::A)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        direction -= 1;
        facing_right = false;
        moved_last_update = true;
    }
    if (   sf::Keyboard::isKeyPressed(sf::Keyboard::D)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        direction += 1;
        facing_right = true;
        moved_last_update  = true;
    }

    float movement {direction * delta.asSeconds() * run_speed};

    float clamped_position{Textured_Object::get_position().x + movement};

    const float low_clamp_x{get_size().x / 2};
    const float high_clamp_x{world.stored_window.getSize().x - (get_size().x / 2)};

    clamped_position = std::clamp(clamped_position, low_clamp_x, high_clamp_x);

    Textured_Object::set_position({clamped_position, get_position().y});
}

void Player::jump(sf::Time delta)
{
    const float JUMP_HEIGHT{200};
    const float JUMP_DURATION_AS_SEC{0.5};

    vertical_duration += delta.asSeconds();

    float progress{vertical_duration / JUMP_DURATION_AS_SEC};

    progress = flip(powf(flip(progress), 2));

    float movement{lerp(0.0f, JUMP_HEIGHT, progress)};

    set_position({center.x, jump_start-movement});

    if (vertical_duration >= JUMP_DURATION_AS_SEC)
    {
        vertical_duration = 0;
        player_state = falling;
    }

}

void Player::fall(sf::Time delta, World &world)
{
    float terminal_v{800};
    const float FALL_DURATION_AS_SEC{0.4};

    if (vertical_duration < FALL_DURATION_AS_SEC)
    {
        vertical_duration += delta.asSeconds();
        float progress{vertical_duration / FALL_DURATION_AS_SEC};
        progress = powf(progress, 2);

        float movement{lerp(0.0f, terminal_v, progress)};

        drop_margin -= movement * delta.asSeconds();
        set_position({center.x, center.y + movement * delta.asSeconds()});
    }
    else
    {
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
        ||  sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            terminal_v = 1000;
        }
        drop_margin -= (terminal_v * delta.asSeconds());
        set_position({ center.x,
                       center.y + (terminal_v * delta.asSeconds()) });
    }

    if (get_bottom() > world.stored_window.getSize().y) //TEMP(?)
    {
        const float OFFSET_Y{world.stored_window.getSize().y - shape.getSize().y/2};

        vertical_duration = 0;
        player_state = standing;
        off_platform = false;
        jump_count = max_jumps;
        drop_margin = 0.0;
        set_position({center.x, OFFSET_Y});
    }
}

bool Player::still_alive()
{
    return health > 0;
}

void Player::render(sf::RenderWindow &window)
{
    Textured_Object::render(window);
    weapon.render(window);
}

void Player::apply_upgrades()
{
    // Default Values
    std::map<std::string, int> player_stats_int{
            {"health*",    100},
            {"damage*",    20},
            {"max_jumps+", 1}
    };
    std::map<std::string, float> player_stats_float{
            {"run_speed*", 500},
            {"fire_rate*", 0.8}
    };


    for (auto it{std::begin(player_info.get_upgrades())};
         it != std::end(player_info.get_upgrades()); ++it)
    {
        for (auto it2{std::begin(it->int_changes)};
             it2 != std::end(it->int_changes); ++it2)
        {
            if (it2->first.back() == '+')
            {
                player_stats_int[it2->first] += it2->second;
            }
            if (it2->first.back() == '*')
            {
                player_stats_int[it2->first] *= it2->second;
            }
            if (it2->first.back() == '=')
            {
                player_stats_int[it2->first] = it2->second;
            }
        }
        for (auto it3{std::begin(it->float_changes)};
             it3 != std::end(it->float_changes); ++it3)
        {
            if (it3->first.back() == '+')
            {
                player_stats_float[it3->first] += it3->second;
            }
            if (it3->first.back() == '*')
            {
                player_stats_float[it3->first] *= it3->second;
            }
            if (it3->first.back() == '=')
            {
                player_stats_float[it3->first] = it3->second;
            }
        }
    }
    Character::health = player_stats_int["health*"];
    Character::damage = player_stats_int["damage*"];
    weapon.damage = player_stats_int["damage*"];
    max_jumps = player_stats_int["max_jumps+"];
    run_speed = player_stats_float["run_speed*"];
    weapon.fire_rate = player_stats_float["fire_rate*"];
}

void Player::handle_animation()
{
    //If the player is standing still
    if(!moved_last_update)
    {
        frame_numbers = {28, 56, 84, 112, 140, 168, 196, 224, 252, 280, 308, 336};
        if(facing_right)
        {
            sf::IntRect texture_rect{0, 0, 28, 32};
            shape.setTextureRect(texture_rect);
            weapon.set_texture_state(Weapon::right);
        }
        else
        {
            sf::IntRect texture_rect{28, 0, -28, 32};
            shape.setTextureRect(texture_rect);
            weapon.set_texture_state(Weapon::left);
        }
    }
    //If the player is running
    else
    {
        if(facing_right)
        {
            if(center.x - x_at_last_frame > 25)
            {
                x_at_last_frame = center.x;
                std::rotate(frame_numbers.begin(), frame_numbers.begin()+1, frame_numbers.end());
            }

            sf::IntRect texture_rect{frame_numbers[0], 0, 28, 32};
            shape.setTextureRect(texture_rect);
            weapon.set_texture_state(Weapon::right);
            weapon.set_position({center.x + 15, center.y});
        }
        else
        {
            if(x_at_last_frame - center.x > 25)
            {
                x_at_last_frame = center.x;
                std::rotate(frame_numbers.begin(), frame_numbers.begin()+1, frame_numbers.end());
            }

            sf::IntRect texture_rect{frame_numbers[0] + 28, 0, -28, 32};
            shape.setTextureRect(texture_rect);
            weapon.set_texture_state(Weapon::left);
            weapon.set_position({center.x - 15, center.y});
        }
    }


}
