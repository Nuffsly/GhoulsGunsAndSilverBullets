//
// Created by marku849 on 2020-12-14.
//

#ifndef PROJECT_GHOST_MONEY_H
#define PROJECT_GHOST_MONEY_H


#include <memory>
#include <SFML/Graphics.hpp>

#include "Textured_Object.h"
#include "../managers/World.h"
#include "Player.h"

/**
 * \brief Simulates gravity for self and handles interaction when colliding with other objects.
 */
class Money : public Textured_Object
{
public:
    Money(const sf::Vector2f &center, std::string const& texture_name);

    bool update(sf::Time const& delta, World &world) override;

private:
    float timer;
    bool falling;

    void fall(sf::Time const& delta, World &world);
    bool handle_collision(World &world);
};

#endif //PROJECT_GHOST_MONEY_H
