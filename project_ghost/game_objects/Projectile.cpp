//
// Created by jimte on 2020-12-10.
//

#include "Projectile.h"

Projectile::Projectile(sf::Vector2f center, const std::string &texture_name, int const damage, float const n_direction)
        :Textured_Object{center, texture_name}, damage{damage}, direction{n_direction}
{
    shape.setRotation(direction);

    const float PI{M_PI};
    //Convert angle to radians
    direction = direction * PI / 180;
}

bool Projectile::update(const sf::Time &delta, World &world)
{
    const float SPEED{2000};

    float x_movement = (SPEED * cosf(direction)) * delta.asSeconds();
    float y_movement = (SPEED * sinf(direction)) * delta.asSeconds();

    set_position({center.x + x_movement, center.y + y_movement});

    return true;
}