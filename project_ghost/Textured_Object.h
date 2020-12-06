//
// Created by jimte on 2020-12-02.
//

#ifndef MAIN_CPP_TEXTURED_OBJECT_H
#define MAIN_CPP_TEXTURED_OBJECT_H

#include "Game_Object.h"
#include "Texture_Manager.h"

//In this file:
//Textured_Object
//Character
//Platform


// Textured_Object Class
class Textured_Object : public Game_Object
{
public:
    Textured_Object(sf::Vector2f const& center, std::string const& texture_name);

    void render(sf::RenderWindow &window) override;

    sf::Vector2f get_position();
    sf::Vector2f get_size();

    void set_position(sf::Vector2f);

private:
    sf::RectangleShape shape;
};

class Character : public Textured_Object
{
public:
    Character(const sf::Vector2f &center, std::string const& texture_name, int health, int damage);

private:
    int health;
    int damage;
};

// Platform Class
class Platform : public Textured_Object
{
public:
    Platform(const sf::Vector2f &center, std::string const& texture_name);

    bool update(const sf::Time &delta, World &world) override;


private:
};


#endif //MAIN_CPP_TEXTURED_OBJECT_H
