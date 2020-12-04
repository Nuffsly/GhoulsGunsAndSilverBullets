//
// Created by jimte on 2020-12-02.
//

#ifndef MAIN_CPP_GAME_OBJECT_H
#define MAIN_CPP_GAME_OBJECT_H
#include <SFML/Graphics.hpp>

class Game_Object
{
public:
    Game_Object(sf::Vector2f center, sf::Vector2f hitbox);

    virtual bool update(sf::Time) = 0;

    virtual void render(sf::RenderWindow &window) = 0;

private:
    sf::Vector2f center;
    sf::Vector2f hitbox;
};

#endif //MAIN_CPP_GAME_OBJECT_H
