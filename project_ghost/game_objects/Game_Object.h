//
// Created by jimte on 2020-12-02.
//

#ifndef MAIN_CPP_GAME_OBJECT_H
#define MAIN_CPP_GAME_OBJECT_H

#include <SFML/Graphics.hpp>
class World;

/**
 * \brief Abstract base for all objects with a hitbox and a position.
 * Handles providing edge position of the hitbox.s
 */
class Game_Object
{
public:
    Game_Object(const sf::Vector2f &center, const sf::Vector2f &hitbox);
    virtual ~Game_Object() = default;

    virtual bool update(const sf::Time &delta, World &world) = 0;

    virtual void render(sf::RenderWindow &window) = 0;

    float get_right() const;
    float get_left() const;
    float get_top() const;
    float get_bottom() const;

    sf::Vector2f center;
    sf::Vector2f hitbox;
};

#endif //MAIN_CPP_GAME_OBJECT_H
