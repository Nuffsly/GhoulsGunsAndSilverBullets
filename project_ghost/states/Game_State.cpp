//
// Created by jimte on 2020-12-11.
//

#include <cmath>
#include <filesystem>
#include <iostream>

#include "Game_State.h"
#include "../game_objects/Enemy.h"

Game_State::Game_State(sf::RenderWindow &window)
: player_info{}, world(window), available_upgrades{}, level{1}, finished_level{false}, enemies_spawned{0}, since_last_spawn{0}
{
    load_upgrades();
    world.load_level(player_info);
    /*world.add_object(std::shared_ptr<Game_Object>(new Platform({200, 550}, "platform.png")));
    world.add_object(std::shared_ptr<Game_Object>(new Platform({328, 550}, "platform.png")));
    world.add_object(std::shared_ptr<Game_Object>(new Platform({456, 550}, "platform.png")));

    world.add_object(std::shared_ptr<Game_Object>(new Platform({800, 550}, "platform.png")));
    world.add_object(std::shared_ptr<Game_Object>(new Platform({928, 550}, "platform.png")));
    world.add_object(std::shared_ptr<Game_Object>(new Platform({1056, 550}, "platform.png")));

    world.add_object(std::shared_ptr<Game_Object>(new Platform({630, 375}, "platform.png")));

    world.add_object(std::shared_ptr<Game_Object>(new Platform({200, 200}, "platform.png")));
    world.add_object(std::shared_ptr<Game_Object>(new Platform({328, 200}, "platform.png")));
    world.add_object(std::shared_ptr<Game_Object>(new Platform({456, 200}, "platform.png")));

    world.add_object(std::shared_ptr<Game_Object>(new Platform({800, 200}, "platform.png")));
    world.add_object(std::shared_ptr<Game_Object>(new Platform({928, 200}, "platform.png")));
    world.add_object(std::shared_ptr<Game_Object>(new Platform({1056, 200}, "platform.png")));

    *//*for (Upgrade &upg : available_upgrades)
    {
        player_info.add_upgrade(upg);
    }*//*
    world.add_object(std::shared_ptr<Game_Object>(new Door({1000, 650}, "door.png")));
    world.add_object(std::shared_ptr<Game_Object>(player_info.create_new_player({500, 500})));*/
}

std::shared_ptr<State> Game_State::tick(sf::Time delta)
{
    if (!finished_level)
    {
        since_last_spawn += delta.asSeconds();
        spawn_enemy();
    }

    world.tick(delta);
    return nullptr;
}

void Game_State::render(sf::RenderWindow &window)
{
    world.render(window);
}

void Game_State::spawn_enemy()
{
    if (since_last_spawn > 2.0f / static_cast<float>(level) && enemies_spawned < 9 + pow(level, 1.3))
    {
        world.add_object(std::shared_ptr<Game_Object>(new Enemy({0, 0}, "enemy.png", 100, 0, world.get_player_ptr())));
        enemies_spawned += 1;
        since_last_spawn = 0;
    }
    else if (enemies_spawned > 9 + pow(level, 1.3))
    {
        finished_level = true;
    }
}

void Game_State::load_upgrades()
{
    std::string file_path{std::filesystem::current_path().string() + "/../game_data/upgrades"};

    std::ifstream f_stream{file_path, std::ios::in};
    if (!f_stream.is_open())
    {
        throw std::logic_error("Failed to load upgrades");
    }
    std::string line{};
    while ( std::getline(f_stream, line) )
    {
        available_upgrades.emplace_back(Upgrade{line});
        std::getline(f_stream, available_upgrades.back().description);
        std::getline(f_stream, line);
        available_upgrades.back().price = stoi(line);
        std::string type_name;
        std::string var_name;
        std::string value;
        while ( type_name != "#" )
        {
            f_stream >> type_name;
            if ( type_name == "#" )
            {
                f_stream.ignore(1000, '\n');
                break;
            }
            f_stream >> var_name;
            f_stream >> value;
            if (type_name == "int")
            {
                available_upgrades.back().int_changes.insert({var_name, stoi(value)} );
            }
            if (type_name == "float")
            {
                available_upgrades.back().float_changes.insert({var_name, stof(value)} );
            }
        }
    }
}
