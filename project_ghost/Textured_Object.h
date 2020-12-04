//
// Created by jimte on 2020-12-02.
//

#ifndef MAIN_CPP_TEXTURED_OBJECT_H
#define MAIN_CPP_TEXTURED_OBJECT_H

#include "Game_Object.h"
//In this file:
//Textured_Object
//Character
//Platform


// Textured_Object Class
class Textured_Object : public Game_Object
{
public:
    Textured_Object(sf::Vector2f center, sf::Vector2f size);

    void render(sf::RenderWindow &window) override;

    sf::Vector2f get_position();
    void set_position(sf::Vector2f);

private:
    sf::RectangleShape shape;
};

class Character : public Textured_Object
{
public:
    Character(sf::Vector2f center, sf::Vector2f size, int health, int damage);

private:
    int health;
    int damage;
};

// Platform Class
class Platform : public Textured_Object
{
public:
    Platform(sf::Vector2f center, sf::Vector2f size);

    bool update(sf::Time) override;
    void render(sf::RenderWindow &window) override;

private:
};


#endif //MAIN_CPP_TEXTURED_OBJECT_H
