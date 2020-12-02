//
// Created by jimte on 2020-12-02.
//

#ifndef MAIN_CPP_TEXTURED_OBJECT_H
#define MAIN_CPP_TEXTURED_OBJECT_H

#include "Game_Object.h"

class Textured_Object : public Game_Object
{
public:
    Textured_Object(sf::Vector2f center, sf::Vector2f size);

    virtual void render(sf::RenderWindow &window);

private:
    sf::RectangleShape shape;
};

class Platform : public Textured_Object
{
public:
    Platform(sf::Vector2f center, sf::Vector2f size);

private:
};


#endif //MAIN_CPP_TEXTURED_OBJECT_H
