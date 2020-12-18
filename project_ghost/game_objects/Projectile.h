//
// Created by jimte on 2020-12-10.
//

#ifndef MAIN_CPP_PROJECTILE_H
#define MAIN_CPP_PROJECTILE_H

#include<SFML/Graphics.hpp>
#include <cmath>

#include "Textured_Object.h"
#include "../managers/World.h"

/**
 * \brief Moves in whatever direction it was spawned in until it reaches specific criteria.
 */
class Projectile : public Textured_Object
{
public:
    Projectile(sf::Vector2f center, std::string const& texture_name, int damage, float direction);

    bool update(sf::Time const& delta, World &world) override;
    bool handle_collision(World &world);
    void handle_movement(sf::Time const& delta, World &world);

private:
    int damage;
    float direction;
};


#endif //MAIN_CPP_PROJECTILE_H
