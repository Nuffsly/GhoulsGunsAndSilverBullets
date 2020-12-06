//
// Created by jimte on 2020-12-06.
//

#include "Weapon.h"

Weapon::Weapon(sf::Vector2f center, const std::string &texture_name, float fire_rate, int damage)
        :Textured_Object{center, texture_name}, fire_rate(fire_rate), damage(damage)
{}

bool Weapon::update(sf::Time const& delta, World &world)
{
    return true;
}