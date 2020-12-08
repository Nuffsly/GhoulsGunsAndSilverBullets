//
// Created by jimte on 2020-12-03.
//

#include <SFML/Window.hpp>
#include <cmath>

#include "Player.h"


Player::Player(sf::Vector2f center, std::string const& texture_name, int health, int damage)
    :Character{center, texture_name, health, damage},
    player_state{0}, jump_start{0.0}, jump_end{0.0}, jumped_time{0.0},
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
            jump_start  = center.y;
            jump_end    = center.y - 200; // number is jump height in pixels
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;

    float delta_in_seconds{delta.asMicroseconds() / 1000000.0f};

    sf::Vector2f movement{direction.x * delta_in_seconds * 500,
                          direction.y * delta_in_seconds * 500};

    sf::Vector2f clamped_position{Textured_Object::get_position() + movement};

    const float low_clamp_x{get_size().x / 2};
    const float low_clamp_y{get_size().y / 2};

    const float high_clamp_x{1000.0f - (get_size().x / 2)};
    const float high_clamp_y{1000.0f - (get_size().y / 2)};

    clamped_position.x = std::clamp(clamped_position.x, low_clamp_x, high_clamp_x);
    clamped_position.y = std::clamp(clamped_position.y, low_clamp_y, high_clamp_y);

    Textured_Object::set_position(clamped_position);

}

void Player::jump(sf::Time delta)
{
    if ( center.y - jump_end > 2 ) //if not at peak
    {
        jumped_time += delta.asSeconds();
        float lerped_pos{jump_start + jumped_time * 2 * (jump_end - jump_start) };
        Textured_Object::set_position({center.x, lerped_pos});
    }
    else
    {
        jump_start = 0.0;
        jump_end = 0.0;
        jumped_time = 0.0;
        player_state = 2; //set falling
    }
}

void Player::fall(sf::Time delta)
{
    Textured_Object::set_position({center.x, center.y+(700 * delta.asSeconds())});
    if ( center.y > 600 ) // TEMP
    {
        player_state = 0;
    }
}

void Player::render(sf::RenderWindow &window)
{
    Textured_Object::render(window);
    weapon.render(window);
}
