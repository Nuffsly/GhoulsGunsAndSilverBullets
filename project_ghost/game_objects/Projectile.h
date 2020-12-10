//
// Created by jimte on 2020-12-10.
//

#ifndef MAIN_CPP_PROJECTILE_H
#define MAIN_CPP_PROJECTILE_H

#include "Textured_Object.h"
#include <cmath>

class Projectile : public Textured_Object
{
public:
    Projectile(sf::Vector2f center, std::string const& texture_name, int damage, float direction);

    bool update(sf::Time const& delta, World &world) override;

    int get_damage() const
    {
        return damage;
    }

private:
    int damage;
    float direction;
};


#endif //MAIN_CPP_PROJECTILE_H
