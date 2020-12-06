//
// Created by jimte on 2020-12-03.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include "Textured_Object.h"
#include "Weapon.h"

class Player : public Character
{
public:
    Player(const sf::Vector2f &center, std::string const &texture_name, int health, int damage);

    bool update(const sf::Time &delta, World &world) override;

    void render(sf::RenderWindow &window) override;

private:
    void move_player(sf::Time delta);

    Weapon weapon;
};


#endif //MAIN_CPP_PLAYER_H
