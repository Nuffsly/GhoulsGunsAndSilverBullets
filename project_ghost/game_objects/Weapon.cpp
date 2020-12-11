//
// Created by jimte on 2020-12-06.
//

#include "Weapon.h"
#include <cmath>
#include <memory>
#include "../managers/World.h"
#include "Projectile.h"



Weapon::Weapon(sf::Vector2f center, const std::string &texture_name,
               float fire_rate, int damage)
        :Textured_Object{center, texture_name}, fire_rate(fire_rate),
        damage(damage), sec_since_fired{0}, direction{0}, barrel_pos{0, 0}
{
    shape.setOrigin(10, 10);
}

bool Weapon::update(sf::Time const& delta, World &world)
{
    const float PI{M_PI};

    sf::Vector2f weapon_pos{center};
    shape.setPosition(center);
    sf::Vector2f mouse_pos{sf::Mouse::getPosition(world.stored_window)};

    direction = std::atan2(mouse_pos.y - weapon_pos.y, mouse_pos.x - weapon_pos.x) * 180 / PI;
    shape.setRotation(direction);

    calc_barrel_pos(direction);

    sec_since_fired += delta.asSeconds();
    return true;
}

void Weapon::shoot(const sf::Time &delta, World &world)
{

    if(sec_since_fired > fire_rate)
    {
        sec_since_fired = 0;
        world.add_object(std::make_shared<Projectile>(
                barrel_pos, "projectile.png", damage, direction));
    }

}

void Weapon::calc_barrel_pos(float direction)
{
    const float PI{M_PI};
    //Convert angle to radians
    direction = direction * PI / 180;

    const float distance{shape.getSize().x-10};

    float x_change = (distance * cosf(direction));
    float y_change = (distance * sinf(direction));

    barrel_pos = {center.x + x_change, center.y + y_change};
}
