//
// Created by jimte on 2020-12-02.
//

#ifndef MAIN_CPP_GAME_OBJECT_H
#define MAIN_CPP_GAME_OBJECT_H
#include <SFML/Graphics.hpp>
#include "World.h"

class Game_Object
{
public:
    Game_Object(const sf::Vector2f &center, const sf::Vector2f &hitbox);

    virtual bool update(const sf::Time &delta, World &world) = 0;

    virtual void render(sf::RenderWindow &window) = 0;

private:
    sf::Vector2f center;
    sf::Vector2f hitbox;
};

#endif //MAIN_CPP_GAME_OBJECT_H
