//
// Created by jimte on 2020-12-03.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include "Textured_Object.h"
#include "Weapon.h"
#include "../managers/World.h"

class Player : public Character
{
public:
    Player(sf::Vector2f center, std::string const &texture_name, int health, int damage);

    bool update(const sf::Time &delta, World &world) override;

    void render(sf::RenderWindow &window) override;

private:
    void move_player(sf::Time delta);
    void jump(sf::Time delta);
    void fall(sf::Time delta);
    void handle_collision(World &world);

    int player_state;
    bool off_platform;
    float duration;
    float jump_start;

    bool jump_pressed;
    int jump_count;
    const int MAX_JUMPS;

    Weapon weapon;
};


#endif //MAIN_CPP_PLAYER_H
