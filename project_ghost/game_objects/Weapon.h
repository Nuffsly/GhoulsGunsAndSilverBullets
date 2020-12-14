//
// Created by jimte on 2020-12-06.
//

#ifndef MAIN_CPP_WEAPON_H
#define MAIN_CPP_WEAPON_H

#include <SFML/Graphics.hpp>

#include "Textured_Object.h"

class World;

class Weapon : public Textured_Object
{
public:
    Weapon(sf::Vector2f center, std::string const& texture_name);

    void shoot(const sf::Time &delta, World &world);
    bool update(sf::Time const& delta, World &world) override;
    void calc_barrel_pos(float const direction);

    float fire_rate;
    int damage;


private:
    float sec_since_fired;
    float direction;
    sf::Vector2f barrel_pos;
};


#endif //MAIN_CPP_WEAPON_H
