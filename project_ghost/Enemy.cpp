//
// Created by marku849 on 2020-12-06.
//
// In this file:
// Money
// Enemy

#include "Enemy.h"
#include "World.h"

Money::Money(const sf::Vector2f &center, const std::string &texture_name)
    :Textured_Object(center, texture_name)
{}

bool Money::update(sf::Time const& delta, World &world)
{
    return true;
}

Enemy::Enemy(const sf::Vector2f &center, const std::string &texture_name,
             int health, int damage, const std::shared_ptr<Game_Object> &player_ptr)
    :Character{center, texture_name, health, damage,}, player_ptr{player_ptr}
{}

bool Enemy::update(const sf::Time &delta, World &world)
{
    move_enemy(delta);

    // check if dead
    if (get_health() <= 0)
    {
        drop_money(world);
        return false; // tells word to remove this object
    }
    else
        {
            return true;
        }
}

void Enemy::move_enemy(const sf::Time &delta)
{
    sf::Vector2f direction;
    if (center.y > player_ptr->center.y)
        direction.y -= 1;
    if(center.y < player_ptr->center.y)
        direction.y += 1;
    if(center.x > player_ptr->center.x)
        direction.x -= 1;
    if(center.x < player_ptr->center.x)
        direction.x += 1;

    float delta_in_seconds{delta.asMicroseconds() / 1000000.0f};

    sf::Vector2f movement{direction.x * delta_in_seconds * 200,
                          direction.y * delta_in_seconds * 200};

    set_position(get_position() + movement);
}

void Enemy::drop_money(World &world)
{
    world.add_object(std::make_shared<Money>(Money{get_position(), "money.png"}));
}

