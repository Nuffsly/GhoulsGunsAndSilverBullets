//
// Created by jimte on 2020-12-03.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include "Textured_Object.h"

class Player : public Character
{
public:
    Player(sf::Vector2f center, std::string const& texture_name, int health, int damage);
    bool update(sf::Time) override;

private:
    void move_player(sf::Time delta);
};


#endif //MAIN_CPP_PLAYER_H
