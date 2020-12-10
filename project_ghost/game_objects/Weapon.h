//
// Created by jimte on 2020-12-06.
//

#ifndef MAIN_CPP_WEAPON_H
#define MAIN_CPP_WEAPON_H

#include "Textured_Object.h"

class Weapon : public Textured_Object
{
public:
    Weapon(sf::Vector2f center, std::string const& texture_name, float fire_rate, int damage);

    void shoot(const sf::Time &delta, World &world);
    bool update(sf::Time const& delta, World &world) override;
    void calc_barrel_pos(float const direction);

private:
    float fire_rate;
    int damage;
    float sec_since_fired;
    float direction;
    sf::Vector2f barrel_pos;
};


#endif //MAIN_CPP_WEAPON_H
