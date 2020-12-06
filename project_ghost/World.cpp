//
// Created by jimte on 2020-12-04.
//

#include "World.h"

void World::tick(sf::Time delta)
{
    for (size_t i = 0; i < game_objects.size(); i++)
    {
        // update returns false if it wants to be deleted
        if (!game_objects[i]->update(delta, *this))
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
        object->render(window);
    }
}

void World::add_object(std::shared_ptr<Game_Object> const& game_object)
{
    game_objects.push_back(game_object);
}
