//
// Created by marku849 on 2020-12-14.
//

#include "Door.h"

Door::Door(const sf::Vector2f &center, const std::string &texture_name)
    :Textured_Object(center, texture_name)
{}

bool Door::update(const sf::Time &delta, World &world)
{
    return true;
}
