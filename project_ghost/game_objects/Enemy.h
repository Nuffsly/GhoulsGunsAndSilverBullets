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
 * \brief This is the class that handles enemies in the game.
 * It is a very interesting class so I write another line.
 */
class Enemy : public Character
{
public:
    Enemy(const sf::Vector2f &center, std::string const& texture_name,
          int health, int damage, std::shared_ptr<Game_Object> player_ptr);

    bool update(const sf::Time &delta, World &world) override;

private:
    std::shared_ptr<Game_Object> player_ptr;

    void move_enemy(sf::Time const& delta); /**< Handles all movement for the enemy */
    void drop_money(World &world);

    float animation_time;
    std::vector<int> frame_numbers;

    float time_alive; /**< Keeps track of how long the enemy has been alive to animate it. */
};


#endif //PROJECT_GHOST_ENEMY_H
