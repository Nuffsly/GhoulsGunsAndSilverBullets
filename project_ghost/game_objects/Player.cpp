//
// Created by jimte on 2020-12-03.
//

#include <SFML/Window.hpp>
#include <cmath>

#include "Player.h"

float lerp(float const a, float const b, float const x)
{
    return ( a + (b - a) * x);
}

float ease_out_expo(float in_f)
{
    return 1 - pow(-10*in_f, 2);
}

Player::Player(sf::Vector2f center, std::string const& texture_name, int health, int damage)
    :Character{center, texture_name, health, damage}, player_state{2}, velocity{0},
    weapon{center, "weapon.png", 1.0f, damage}
{}

bool Player::update(const sf::Time &delta, World &world)
{
    move_player(delta);
    weapon.set_position(center);
    weapon.update(delta, world);
    return true;
}

void Player::move_player(sf::Time delta)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (player_state != 1 && player_state != 2) // if not falling or jumping
        {
            velocity = 2000;
            player_state = 1; // jumping
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

void Player::jump(sf::Time delta)
{
    velocity = velocity - 2.5f * sqrtf(velocity) + 100 * delta.asSeconds();

    Textured_Object::set_position({center.x, center.y - velocity * delta.asSeconds()});
    if (velocity < 80 )
    {
        player_state = 2;
        velocity = 30;
    }
}

void Player::fall(sf::Time delta)
{
    const float TERMINAL_V{1000};
    if (velocity < TERMINAL_V)
    {
        velocity = velocity + pow(velocity, 2) * 0.002f + 200 * delta.asSeconds();
    }
    else
    {
        velocity = TERMINAL_V;
    }
    Textured_Object::set_position({center.x, center.y + velocity * delta.asSeconds()});
    if ( center.y > 600 ) // TEMP - will check collision with platforms
    {
        player_state = 0;
        velocity = 0;
    }
}

void Player::render(sf::RenderWindow &window)
{
    Textured_Object::render(window);
    weapon.render(window);
}
