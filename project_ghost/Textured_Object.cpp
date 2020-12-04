//
// Created by jimte on 2020-12-02.
//

#include "Textured_Object.h"

Textured_Object::Textured_Object(sf::Vector2f center, sf::Vector2f size)
:Game_Object{center, size}
{
    shape.setSize({size.x, size.y});
    shape.setOrigin(size.x/2, size.y/2);
    shape.setPosition(center);
}

void Textured_Object::render(sf::RenderWindow &window)
{
    window.draw(shape);
}

sf::Vector2f Textured_Object::get_position()
{
    return shape.getPosition();
}

void Textured_Object::set_position(sf::Vector2f position)
{
    shape.setPosition(position);
}


// Character

Character::Character(sf::Vector2f center, sf::Vector2f size, int health, int damage)
    :Textured_Object{center, size}, health{health}, damage{damage}
{}


//Platform

bool Platform::update(sf::Time)
{return true;}

Platform::Platform(sf::Vector2f center, sf::Vector2f size)
:Textured_Object{center, size}
{};