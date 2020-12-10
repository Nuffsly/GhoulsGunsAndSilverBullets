//
// Created by jimte on 2020-12-03.
//

#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>

#include "Player.h"

float lerp(float const a, float const b, float const t)
{
    return ( a + (b - a) * t);
}

float flip(float const x)
{
    return 1-x;
}

float ease_out_expo(float in_f)
{
    return 1 - pow(-10*in_f, 2);
}

Player::Player(sf::Vector2f center, std::string const& texture_name, int health, int damage)
    :Character{center, texture_name, health, damage}, player_state{2}, duration{0.0}, jump_start{0.0},
    weapon{center, "weapon.png", 1.0f, damage}
{}

bool Player::update(const sf::Time &delta, World &world)
{
    move_player(delta);

    weapon.set_position(center);
    weapon.update(delta, world);

    handle_collision(world);

    return true;
}

void Player::move_player(sf::Time delta)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (player_state != 1 && player_state != 2) // if not falling or jumping
        {
            player_state = 1; // jumping
            jump_start = center.y;
        }
    }
    if (player_state == 1)
    {
        jump(delta);
    }
    if ( player_state == 2 )
    {
        fall(delta);
    }

    sf::Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;

    float delta_in_seconds{delta.asMicroseconds() / 1000000.0f};

    sf::Vector2f movement{direction.x * delta_in_seconds * 500,
                          direction.y * delta_in_seconds * 500};

    sf::Vector2f clamped_position{Textured_Object::get_position() + movement};

    const float low_clamp_x{get_size().x / 2};

    const float high_clamp_x{1280.0f - (get_size().x / 2)};

    clamped_position.x = std::clamp(clamped_position.x, low_clamp_x, high_clamp_x);

    Textured_Object::set_position(clamped_position);

}

void Player::handle_collision(World &world)
{
    for (auto &collision : world.collides_with(*this))
    {
        if (dynamic_cast<Platform *>(collision.get()))
        {
            float player_bottom_edge{center.y + shape.getSize().y / 2};
            float platform_top_edge{collision->center.y - collision->hitbox.y / 2};
            const float MARGIN {30};

            if ( player_state == 2 // falling
                && player_bottom_edge > platform_top_edge
                &&  player_bottom_edge < platform_top_edge + MARGIN)
            {
                player_state = 0;

                set_position({center.x, platform_top_edge - shape.getSize().y/2});
                duration = 0;
                jump_start = 0;
            }
        }

    }
}

void Player::jump(sf::Time delta)
{
    const float JUMP_HEIGHT{200};
    const float JUMP_DURATION_AS_SEC{0.5};

    duration += delta.asSeconds();

    float progress{duration / JUMP_DURATION_AS_SEC};

    progress = flip(powf(flip(progress), 2));

    float movement{lerp(0.0f, JUMP_HEIGHT, progress)};

    set_position({center.x, jump_start-movement});

    if (duration >= JUMP_DURATION_AS_SEC)
    {
        duration = 0;
        player_state = 2;
    }

}

void Player::fall(sf::Time delta)
{
    float terminal_v{800};
    const float FALL_DURATION_AS_SEC{0.4};

    if (duration < FALL_DURATION_AS_SEC)
    {
        duration += delta.asSeconds();
        float progress{duration / FALL_DURATION_AS_SEC};
        progress = powf(progress, 2);

        float movement{lerp(0.0f, terminal_v, progress)};

        set_position({center.x, center.y + movement * delta.asSeconds()});
    }
    else
    {
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
        ||  sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            terminal_v = 1250;
        }
        set_position({ center.x,
                       center.y + (terminal_v * delta.asSeconds()) });
    }

    if (center.y > 610) //TEMP(?)
    {
        duration = 0;
        player_state = 0;
        set_position({center.x, 610.0f});
    }
}

void Player::render(sf::RenderWindow &window)
{
    Textured_Object::render(window);
    weapon.render(window);
}
