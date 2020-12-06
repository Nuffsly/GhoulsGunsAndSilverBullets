//
// Created by marku849 on 2020-12-06.
//
// In this file:
// Money
// Enemy

#ifndef PROJECT_GHOST_ENEMY_H
#define PROJECT_GHOST_ENEMY_H

#include "Textured_Object.h"

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
    Enemy(const sf::Vector2f &center, std::string const& texture_name, int health, int damage);

    bool update(const sf::Time &delta, World &world) override;
private:
    void drop_money(World &world);
};


#endif //PROJECT_GHOST_ENEMY_H
