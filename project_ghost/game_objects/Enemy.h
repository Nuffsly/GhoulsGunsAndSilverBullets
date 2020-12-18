//
// Created by marku849 on 2020-12-06.
//

#ifndef PROJECT_GHOST_ENEMY_H
#define PROJECT_GHOST_ENEMY_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Textured_Object.h"

class Player;

/**
 * \brief Handles enemy movement and collision with specific objects.
 */
class Enemy : public Character
{
public:
    Enemy(const sf::Vector2f &center, std::string const& texture_name,
          int health, int damage, std::shared_ptr<Game_Object> player_ptr);

    bool update(const sf::Time &delta, World &world) override; /**< runs necessary subroutines for enemy to function */

private:
    std::shared_ptr<Game_Object> player_ptr;

    void move_enemy(sf::Time const& delta);
    void drop_money(World &world);

    float animation_time;
    std::vector<int> frame_numbers;

    float time_alive;
};


#endif //PROJECT_GHOST_ENEMY_H
