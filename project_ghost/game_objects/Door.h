//
// Created by marku849 on 2020-12-14.
//

#ifndef PROJECT_GHOST_DOOR_H
#define PROJECT_GHOST_DOOR_H

#include <SFML/Graphics.hpp>

#include "Textured_Object.h"

/**
 * \brief Exists to give player something to collide with as a criteria for specific actions.
 */
class Door : public Textured_Object
{
public:
    Door(const sf::Vector2f &center, std::string const &texture_name);

    bool update(const sf::Time &delta, World &world) override;

};


#endif //PROJECT_GHOST_DOOR_H
