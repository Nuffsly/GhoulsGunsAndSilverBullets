//
// Created by marku849 on 2020-12-06.
//
// In this file:
// Money
// Enemy

#include "Enemy.h"

Money::Money(const sf::Vector2f &center, const std::string &texture_name)
    :Textured_Object(center, texture_name)
{}

bool Money::update(sf::Time const& delta, World &world)
{
    return true;
}

Enemy::Enemy(const sf::Vector2f &center, const std::string &texture_name, int health, int damage)
    :Character{center, texture_name, health, damage}
{}

bool Enemy::update(const sf::Time &delta, World &world)
{
    return true;
}

void Enemy::drop_money(World &world)
{

}

