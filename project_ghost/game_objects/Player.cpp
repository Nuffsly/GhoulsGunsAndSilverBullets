//
// Created by jimte on 2020-12-03.
//

#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>

#include "Player.h"
#include "Enemy.h"

float lerp(float const a, float const b, float const t)
{
    return ( a + (b - a) * t);
}

float flip(float const x)
{
    return 1-x;
}


Player::Player(sf::Vector2f center, std::string const& texture_name, int health, int damage)
    : Character{center, texture_name, health, damage},
      player_state{2}, off_platform{false}, drop_margin{0.0},
      vertical_duration{0.0}, horizontal_duration{0.0}, jump_start{0.0},
      inertia{false}, moved_last_update{false}, facing_right{true},
      jump_pressed{false}, jump_count{1}, MAX_JUMPS{1},
      weapon{center, "weapon.png", 0.5, damage}
{
    const float HAT_MARGIN{25.0f};
    hitbox = {(hitbox.x - HAT_MARGIN), hitbox.y};
}

bool Player::update(const sf::Time &delta, World &world)
{
    move_player(delta);

    handle_weapon(delta, world);
    handle_collision(world);

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

void Player::move_player(sf::Time delta)
{
    handle_horizontal_move(delta);

    handle_jump_input();

    handle_drop();

    if (player_state == 1)
    {
        jump(delta);
    }
    if ( player_state == 2 )
    {
        fall(delta);
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
                player_state = 0; //standing
                vertical_duration = 0;
                jump_start = 0;
                jump_count = MAX_JUMPS;

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
            take_damage(dynamic_cast<Enemy *>(collision.get())->get_damage());
        }
    }
    if ( player_state == 0 && off_platform ) // off_platform only sets falling state if all platforms agree
    {
        player_state = 2;
    }
}

void Player::handle_jump_input()
{
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space ) && !jump_pressed)
    {
        jump_pressed = true;
        if (jump_count > 0)
        {
            player_state = 1; // jumping
            jump_start = center.y;
            jump_count--;
            vertical_duration = 0;
            drop_margin = 0.0;
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
        player_state = 2;
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

void Player::handle_horizontal_move(sf::Time delta)
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

    float movement {direction * delta.asSeconds() * 500};

    float clamped_position{Textured_Object::get_position().x + movement};

    const float low_clamp_x{get_size().x / 2};
    const float high_clamp_x{1280.0f - (get_size().x / 2)};

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
        player_state = 2;
    }

}

void Player::fall(sf::Time delta)
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

    if (center.y > 720) //TEMP(?)
    {
        vertical_duration = 0;
        player_state = 0;
        off_platform = false;
        jump_count = MAX_JUMPS;
        drop_margin = 0.0;
        set_position({center.x, 720.0f});
    }
}

bool Player::still_alive()
{
    return get_health() > 0;
}

void Player::render(sf::RenderWindow &window)
{
    Textured_Object::render(window);
    weapon.render(window);
}
