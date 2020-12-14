//
// Created by jimte on 2020-12-10.
//

#include "Projectile.h"
#include "Enemy.h"
#include "../managers/Sound_Manager.h"

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
    handle_movement(delta, world);

    if(center.x < 0 || center.x > world.stored_window.getSize().x
    || center.y < 0 || center.y > world.stored_window.getSize().y)
    {
        return false;
    }

    return handle_collision(world);
}

bool Projectile::handle_collision(World &world)
{
    for (auto &collision : world.collides_with(*this))
    {
        if (dynamic_cast<Enemy *>(collision.get()))
        {
            dynamic_cast<Enemy *>(collision.get())->take_damage(damage);
            Sound_Manager::play_sound("hit.wav");
            return false;
        }
    }
    return true;
}

void Projectile::handle_movement(const sf::Time &delta, World &world)
{
    const float SPEED{2000};

    float x_movement = (SPEED * cosf(direction)) * delta.asSeconds();
    float y_movement = (SPEED * sinf(direction)) * delta.asSeconds();

    set_position({center.x + x_movement, center.y + y_movement});
}
