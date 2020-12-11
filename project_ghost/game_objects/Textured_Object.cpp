//
// Created by jimte on 2020-12-02.
//

#include "Textured_Object.h"

Textured_Object::Textured_Object(sf::Vector2f const& center, std::string const& texture_name)
:Game_Object{center, {0, 0}}
{
    const float SCALE{4};

    sf::Texture *texture{Texture_Manager::get_texture(texture_name)};
    sf::Vector2f size{texture->getSize()};

    size = {size.x * SCALE, size.y * SCALE};

    shape.setSize(size);
    shape.setTexture(texture);
    shape.setOrigin(size.x/2, size.y/2);
    shape.setPosition(center);
    hitbox = size;
}

void Textured_Object::render(sf::RenderWindow &window)
{
    window.draw(shape);
}

sf::Vector2f Textured_Object::get_position()
{
    return shape.getPosition();
}

sf::Vector2f Textured_Object::get_size()
{
    return shape.getSize();
}

void Textured_Object::set_position(sf::Vector2f position)
{
    shape.setPosition(position);
    this->center = position;
}


// Character

Character::Character(const sf::Vector2f &center, std::string const& texture_name, int health, int damage)
    :Textured_Object{center, texture_name}, health{health}, damage{damage}
{}

int Character::get_health() const
{
    return health;
}

void Character::take_damage(const int damage_taken)
{
    health -= damage_taken;
}

int Character::get_damage() const
{
    return damage;
}


//Platform

bool Platform::update(const sf::Time &delta, World &world)
{return true;}

Platform::Platform(const sf::Vector2f &center, std::string const& texture_name)
    :Textured_Object{center, texture_name}
{};

Door::Door(const sf::Vector2f &center, const std::string &texture_name)
    :Textured_Object{center, texture_name}
{}

bool Door::update(const sf::Time &delta, World &world)
{
    return true;
}
