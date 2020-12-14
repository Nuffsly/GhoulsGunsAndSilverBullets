//
// Created by jimte on 2020-12-06.
//

#include <cmath>
#include <memory>
#include <SFML/Audio.hpp>

#include "Weapon.h"
#include "Projectile.h"
#include "../managers/Sound_Manager.h"


Weapon::Weapon(sf::Vector2f center, const std::string &texture_name)
        :Textured_Object{center, texture_name}, fire_rate{0},
        damage{0}, sec_since_fired{0}, direction{0}, barrel_pos{0, 0}
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
        Sound_Manager::play_sound("shoot.wav");
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

void Weapon::set_texture_state(Weapon::texture_state state)
{
    sf::IntRect texture_rect{};
    switch (state)
    {
        case right:
            shape.setOrigin(10, 10);
            texture_rect = {0, 0, 23, 6};
            shape.setTextureRect(texture_rect);
            break;

        case left:
            shape.setOrigin(10, 14);
            texture_rect = {0, 6, 23, -6};
            shape.setTextureRect(texture_rect);
            break;

        default:
            break;
    }
}
