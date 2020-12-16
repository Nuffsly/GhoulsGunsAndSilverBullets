//
// Created by marku849 on 2020-12-06.
//
// In this file:
// Enemy

#include <iostream>
#include <utility>
#include <cmath>

#include "Enemy.h"
#include "Money.h"
#include "Player.h"

Enemy::Enemy(const sf::Vector2f &center, const std::string &texture_name,
             int health, int damage, std::shared_ptr<Game_Object> player_ptr)
    :Character{center, texture_name, health, damage},
    player_ptr{std::move(player_ptr)}, animation_time{0},
    frame_numbers{0, 24, 48, 72, 96, 120, 144, 168}, time_alive{0}
{
    //Fix enemies hitbox. Can't use base because of animations
    const float SCALE{4};

    sf::Vector2f size{shape.getTexture()->getSize()};

    size = {size.x/8 * SCALE, size.y * SCALE};
    sf::IntRect texture_rect{frame_numbers[0], 0, 24, 24};

    hitbox = size;
    shape.setTextureRect(texture_rect);
    shape.setSize(size);
    shape.setOrigin(size.x/2, size.y/2);
    shape.setPosition(center);
}

bool Enemy::update(const sf::Time &delta, World &world)
{
    time_alive += delta.asSeconds();

    move_enemy(delta);

    animation_time += delta.asMilliseconds();
    // Handle animation
    if (animation_time > 200)
    {
        animation_time = 0;
        std::rotate(frame_numbers.begin(), frame_numbers.begin()+1, frame_numbers.end());
        sf::IntRect texture_rect{frame_numbers[0], 0, 24, 24};
        shape.setTextureRect(texture_rect);
    }


    // check if dead
    if (health <= 0)
    {
        drop_money(world);
        dynamic_cast<Player *>(player_ptr.get())->player_info.add_enemies_killed(1);
        dynamic_cast<Player *>(player_ptr.get())->player_info.add_score(max_health);
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
    if (center.y > player_ptr->center.y + 50)
        direction.y -= 1;
    if(center.y < player_ptr->center.y - 50)
        direction.y += 1;
    if(center.x > player_ptr->center.x + 50)
        direction.x -= 1;
    if(center.x < player_ptr->center.x - 50)
        direction.x += 1;

    float len = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    if (len > 0.0f)
    {
        direction *= (1.0f / len);
    }

    if (abs(direction.x) > abs(direction.y))
    {
        direction.y += sinf(time_alive * 5);
    } else
    {
        direction.x += sinf(time_alive * 5);
    }

    sf::Vector2f movement{direction.x * delta.asSeconds() * 200,
                          direction.y * delta.asSeconds() * 200};

    set_position(get_position() + movement);
}

void Enemy::drop_money(World &world)
{
    world.add_back(std::make_shared<Money>(Money{get_position(), "money.png"}));
}

