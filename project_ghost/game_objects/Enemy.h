//
// Created by marku849 on 2020-12-06.
//

#ifndef PROJECT_GHOST_ENEMY_H
#define PROJECT_GHOST_ENEMY_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "Textured_Object.h"

class Player;

class Enemy : public Character
{
public:
    Enemy(const sf::Vector2f &center, std::string const& texture_name,
          int health, int damage, std::shared_ptr<Game_Object> player_ptr);

    bool update(const sf::Time &delta, World &world) override;

private:
    std::shared_ptr<Game_Object> player_ptr;
    int max_health;

    void move_enemy(sf::Time const& delta);
    void drop_money(World &world);
};


#endif //PROJECT_GHOST_ENEMY_H
