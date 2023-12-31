//
// Created by jimte on 2020-12-04.
//

#include <iostream>
#include <memory>

#include "World.h"

class Enemy;

World::World(sf::RenderWindow &window)
        :stored_window{window}
{}

void World::tick(sf::Time delta)
{
    for (size_t i = 0; i < game_objects.size(); i++)
    {
        // update returns false if object wants to be deleted
        if (!game_objects[i]->update(delta, *this))
        {
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

void World::clear_level()
{
    game_objects.clear();
    game_objects.shrink_to_fit();
}

void World::add_front(std::shared_ptr<Game_Object> const& game_object)
{
    game_objects.insert(game_objects.begin(), game_object);
}

void World::add_back(std::shared_ptr<Game_Object> const& game_object)
{
    game_objects.push_back(game_object);
}

void World::insert_at(std::shared_ptr<Game_Object> const &game_object, int const index)
{
    game_objects.insert(game_objects.begin() + index, game_object);
}

bool World::collides(Game_Object const& a, Game_Object const& b) const
{
    if(    (a.hitbox.x/2 + b.hitbox.x/2) > std::abs(a.center.x - b.center.x)
        &&  (a.hitbox.y/2 + b.hitbox.y/2) > std::abs(a.center.y - b.center.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<std::shared_ptr<Game_Object>> World::collides_with(Game_Object &me) const
{
    std::vector<std::shared_ptr<Game_Object>> result;
    for (auto &object : game_objects)
    {
        if (object.get() != &me && collides(*object, me))
        {
            result.push_back(object);
        }
    }
    return result;
}