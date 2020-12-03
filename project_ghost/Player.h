//
// Created by jimte on 2020-12-03.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include "Textured_Object.h"

class Player : public Character
{
public:
    Player(sf::Vector2f center, sf::Vector2f size, int health, int damage);
    void update(sf::Time) override;

private:
    void move_player();
};


#endif //MAIN_CPP_PLAYER_H
