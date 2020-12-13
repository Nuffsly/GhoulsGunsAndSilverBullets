//
// Created by jimte on 2020-12-04.
//

#include "World.h"
#include "../containers/Player_Info.h"

#include <iostream>
#include <filesystem>
//#include <fstream>


World::World(sf::RenderWindow &window)
        :stored_window{window}
{}

void World::tick(sf::Time delta)
{
    for (size_t i = 0; i < game_objects.size(); i++)
    {
        // update returns false if it wants to be deleted
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

void World::add_object(std::shared_ptr<Game_Object> const& game_object)
{
    game_objects.push_back(game_object);
}

std::shared_ptr<Game_Object> World::get_player_ptr() const
{
    for (auto game_object : game_objects)
        if(dynamic_cast<Player *>(game_object.get()))
        {
            return game_object;
        }
    return nullptr;
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

void World::load_level(Player_Info &player_info)
{
    std::string file_path{std::filesystem::current_path().string() + "/../game_data/levels/level_prototype.txt"};

    std::ifstream f_stream{file_path, std::ios::in};
    if (!f_stream.is_open())
    {
        throw std::logic_error("Failed to load level");
    }

    char block;
    for( int i{0}; i <= 40; i++ )
    {
        block = f_stream.get();

        if (block == '_')
        {
            add_object(std::shared_ptr<Game_Object>(
                    new Platform(
                            { static_cast<float>( (i * 180) + 64 ),
                                     static_cast<float>( (i / 10) * 180 ) },
                                     "platform.png") ));
        }
        if ( block == 'P')
        {
            add_object(std::shared_ptr<Game_Object>(
                    player_info.create_new_player(
                            {static_cast<float>( (i*180) + 36),
                             static_cast<float>( ( (i/10) * 180 ) - 64 )})));
        }
        if ( i % 10 == 0 && i != 0)
        {
            f_stream.ignore(1000, '\n');
        }
    }

}
