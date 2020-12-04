//
// Created by jimte on 2020-12-04.
//

#include "World.h"

void World::tick(sf::Time delta)
{
    for (size_t i = 0; i < game_objects.size(); i++)
    {
        if (!game_objects[i].update(delta))
        {
            // Remove this element.
            game_objects.erase(game_objects.begin() + i);
            i--;
        }
    }
}

void World::render(sf::RenderWindow &window)
{
    for (auto &object : game_objects)
    {
        object.render(window);
    }
}

