//
// Created by jimte on 2020-12-02.
//

#ifndef MAIN_CPP_TEXTURED_OBJECT_H
#define MAIN_CPP_TEXTURED_OBJECT_H

#include "Game_Object.h"
#include "../managers/Texture_Manager.h"

// In this file:
// Textured_Object
// Character
// Platform


// Textured_Object Class
/**
 * \brief Abstract base for all visible objects. Handles setting the texture and a basic hitbox.
 * Also handles movement of the texture and center.
 */
class Textured_Object : public Game_Object
{
public:
    Textured_Object(sf::Vector2f const &center, std::string const &texture_name);

    virtual void render(sf::RenderWindow &window) override;

    sf::Vector2f get_position();

    sf::Vector2f get_size();

    void set_position(sf::Vector2f);

protected:
    sf::RectangleShape shape;
};

/**
 * \brief Abstract base for all objects with health and damage.
 */
class Character : public Textured_Object
{
public:
    Character(const sf::Vector2f &center, std::string const &texture_name, int health, int damage);

    void take_damage(int damage_taken);

    int health;
    int damage;
    int max_health;
};

// Platform Class
/**
 * \brief Has no function except to be interacted with in special ways.
 * All interaction is handled in the other object when colliding.
 */
class Platform : public Textured_Object
{
public:
    Platform(const sf::Vector2f &center, std::string const &texture_name);

    bool update(const sf::Time &delta, World &world) override;
};


#endif //MAIN_CPP_TEXTURED_OBJECT_H
