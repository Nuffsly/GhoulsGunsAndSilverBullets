//
// Created by marku849 on 2020-12-06.
//

#ifndef PROJECT_GHOST_ENEMY_H
#define PROJECT_GHOST_ENEMY_H

#include "Textured_Object.h"

class Enemy : public Character
{
public:
    Enemy(sf::Vector2f center, std::string const& texture_name, int health, int damage);

    bool update(sf::Time) override;
private:
    void drop_money();
};


#endif //PROJECT_GHOST_ENEMY_H
