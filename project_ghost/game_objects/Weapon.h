//
// Created by jimte on 2020-12-06.
//

#ifndef MAIN_CPP_WEAPON_H
#define MAIN_CPP_WEAPON_H

#include <SFML/Graphics.hpp>

#include "Textured_Object.h"

class World;


/**
 * \brief Handles rotation of the arm and weapon as well as spawning projectiles.
 */
class Weapon : public Textured_Object
{
public:
    Weapon(sf::Vector2f center, std::string const& texture_name);

    void shoot(const sf::Time &delta, World &world);
    bool update(sf::Time const& delta, World &world) override;
    void calc_barrel_pos(float const direction); /**<Calculates where the barrel is to spawn the projectile accurately*/

    enum texture_state{right, left};
    void set_texture_state(texture_state state);

    float fire_rate;
    int damage;


private:
    float sec_since_fired;
    float direction;
    sf::Vector2f barrel_pos;
    sf::Vector2f mouse_pos_last;
};


#endif //MAIN_CPP_WEAPON_H
