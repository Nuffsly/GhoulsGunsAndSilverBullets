//
// Created by jimte on 2020-12-03.
//

#include <SFML/Window.hpp>
#include "Player.h"

Player::Player(sf::Vector2f center, sf::Vector2f size, int health, int damage)
    :Character{center, size, health, damage}
{}

bool Player::update(sf::Time)
{
    move_player();
}

void Player::move_player()
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

    Textured_Object::set_position(Textured_Object::get_position() + direction);
}
