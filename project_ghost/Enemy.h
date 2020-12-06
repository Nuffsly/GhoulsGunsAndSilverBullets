//
// Created by marku849 on 2020-12-06.
//
// In this file:
// Money
// Enemy

#ifndef PROJECT_GHOST_ENEMY_H
#define PROJECT_GHOST_ENEMY_H

#include "Textured_Object.h"
#include "Player.h"

#include <memory>

class Money : public Textured_Object
{
public:
    Money(const sf::Vector2f &center, std::string const& texture_name);

    bool update(sf::Time const& delta, World &world) override;

private:

};

class Enemy : public Character
{
public:
    Enemy(const sf::Vector2f &center, std::string const& texture_name,
          int health, int damage, const std::shared_ptr<Game_Object> &player_ptr);

    bool update(const sf::Time &delta, World &world) override;
private:
    std::shared_ptr<Game_Object> player_ptr;

    void move_enemy(sf::Time const& delta);
    void drop_money(World &world);
};


#endif //PROJECT_GHOST_ENEMY_H
