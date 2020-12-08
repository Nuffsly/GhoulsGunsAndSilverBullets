//
// Created by jimte on 2020-12-06.
//

#include "Weapon.h"
#include <cmath>
#include "../managers/World.h"

Weapon::Weapon(sf::Vector2f center, const std::string &texture_name, float fire_rate, int damage)
        :Textured_Object{center, texture_name}, fire_rate(fire_rate), damage(damage)
{
    shape.setOrigin(10, 10);
}

bool Weapon::update(sf::Time const& delta, World &world)
{
    const float PI{M_PI};

    sf::Vector2f weapon_pos{center};
    shape.setPosition(center);
    sf::Vector2f mouse_pos{sf::Mouse::getPosition()};

    float angle{std::atan2(mouse_pos.y - weapon_pos.y, mouse_pos.x - weapon_pos.x) * 180 / PI};
    shape.setRotation(angle);
    return true;
}