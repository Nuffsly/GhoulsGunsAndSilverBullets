//
// Created by jimte on 2020-12-06.
//

#include "Weapon.h"
#include <cmath>
#include "../managers/World.h"
#include "Projectile.h"



Weapon::Weapon(sf::Vector2f center, const std::string &texture_name, float fire_rate, int damage)
        :Textured_Object{center, texture_name}, fire_rate(fire_rate), damage(damage), sec_since_fired{0}, direction{0}
{
    shape.setOrigin(10, 10);
}

bool Weapon::update(sf::Time const& delta, World &world)
{
    const float PI{M_PI};

    sf::Vector2f weapon_pos{center};
    shape.setPosition(center);
    sf::Vector2f mouse_pos{sf::Mouse::getPosition()};

    direction = std::atan2(mouse_pos.y - weapon_pos.y, mouse_pos.x - weapon_pos.x) * 180 / PI;
    shape.setRotation(direction);

    sec_since_fired += delta.asSeconds();
    return true;
}

void Weapon::shoot(const sf::Time &delta, World &world)
{

    if(sec_since_fired > fire_rate)
    {
        sec_since_fired = 0;
        world.add_object(std::shared_ptr<Projectile>(
                new Projectile{center, "projectile.png", damage, direction}));
    }

}
