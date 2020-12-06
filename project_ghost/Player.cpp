//
// Created by jimte on 2020-12-03.
//

#include <SFML/Window.hpp>
#include "Player.h"

Player::Player(const sf::Vector2f &center, std::string const& texture_name, int health, int damage)
    :Character{center, texture_name, health, damage}, weapon{center, "weapon.png", 1.0f, damage}
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

void Player::render(sf::RenderWindow &window)
{
    Textured_Object::render(window);
    weapon.render(window);
}
