//
// Created by marku849 on 2020-12-06.
//

#include "Enemy.h"

Enemy::Enemy(sf::Vector2f center, const std::string &texture_name, int health, int damage)
    :Character{center, texture_name, health, damage}
{}

bool Enemy::update(sf::Time)
{
    return true;
}

void Enemy::drop_money()
{

}

