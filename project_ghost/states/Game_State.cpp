//
// Created by jimte on 2020-12-11.
//

#include <cmath>
#include <filesystem>
#include <iostream>
#include <random>

#include "Game_State.h"
#include "../game_objects/Upgrade_Pillar.h"
#include "../game_objects/Door.h"


Game_State::Game_State(sf::RenderWindow &window)
    : player_info{}, world(window), available_upgrades{}, level{1},
      finished_level{false}, enemies_spawned{0}, total_enemies_spawned{0},
      since_last_spawn{0}
{
    load_upgrades();

    // For testing upgrades
    for (Upgrade &upg : available_upgrades)
    {
        player_info.add_upgrade(upg);
    }

    load_level();
}

std::shared_ptr<State> Game_State::tick(sf::Time delta)
{
    if (!finished_level)
    {
        since_last_spawn += delta.asSeconds();
        spawn_enemy();
    }

    if (since_last_spawn > 5.0
    && total_enemies_spawned == player_info.get_enemies_killed() )
    {
        finished_level = true;
    }

    if (finished_level && door_pos != sf::Vector2f{0, 0})
    {
        std::random_device rd;

        for (sf::Vector2f &pillar_pos : upg_pillars_pos)
        {
            std::uniform_int_distribution<int> uniform(0,available_upgrades.size()-1);
            int i{uniform(rd)};

            world.add_before_back(std::shared_ptr<Game_Object>(
                    new Upgrade_Pillar( pillar_pos,
                                        "upgrade.png",
                                        available_upgrades[i] ) ));
        }

        world.add_front(std::shared_ptr<Game_Object>(
                new Door( door_pos, "door.png") ));
        door_pos = {0, 0};
    }

    if (player_info.exited_level)
    {
        reset_world();
        level += 1;
        load_level();
    }

    if ( !player_info.is_alive )
    {
        return std::make_shared<Exit_State>();
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
        const unsigned int X_RES{world.stored_window.getSize().x};
        const unsigned int Y_RES{world.stored_window.getSize().y};

        std::random_device rd;
        std::uniform_int_distribution<int> sides(1,3);
        int side{sides(rd)};
        sf::Vector2f center;

        if (side == 1)
        {
            std::uniform_int_distribution<int> x_axis(1,X_RES);
            center = {static_cast<float>(x_axis(rd)), -100};
        }
        if (side == 2)
        {
            std::uniform_int_distribution<int> y_axis(1,Y_RES);
            center = {-100, static_cast<float>(y_axis(rd))};
        }
        if (side == 3)
        {
            std::uniform_int_distribution<int> y_axis(1,Y_RES);
            center = {static_cast<float>(X_RES+100), static_cast<float>(y_axis(rd))};
        }
        world.add_back(std::shared_ptr<Game_Object>(
                new Enemy({center},
                          "enemy.png", 30*(1+level/10),
                          15*(1+level/10), player_ptr)));
        enemies_spawned += 1;
        total_enemies_spawned += 1;
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
            if (type_name == "int" || type_name == "float")
            {
                available_upgrades.back().number_changes.insert({var_name, stof(value)} );
            }
        }
    }
}

void Game_State::load_level()
{
    const int NUMBER_OF_LEVELS{3};

    std::random_device rd;
    std::uniform_int_distribution<int> uniform(1,NUMBER_OF_LEVELS);

    std::string file_path{std::filesystem::current_path().string()
                                    + "/../game_data/levels/"
                                    + std::to_string(uniform(rd))};

    std::ifstream f_stream{file_path, std::ios::in};
    if (!f_stream.is_open())
    {
        throw std::logic_error("Failed to load level");
    }

    char block;
    for (int i{0}; i <= 40; i++)
    {
        block = f_stream.get();

        if (block == '_' || block == 'B')
        {
            const int HALF_WIDTH{64};

            world.add_front(std::shared_ptr<Game_Object>(
                    new Platform(
                            {static_cast<float>(( i % 10 * 128) + HALF_WIDTH ),
                             static_cast<float>(( 1 + (i / 10)) * 180 )},
                            "platform.png")));
        }
        if (block == 'P' || block == 'B')
        {
            const int HALF_WIDTH{36};
            const int HALF_HEIGHT{64};

            player_ptr = std::shared_ptr<Game_Object>(
                    new Player(
                             {static_cast<float>(( i % 10 * 128) + HALF_WIDTH ),
                             static_cast<float>(( 1 + (i / 10)) * 180 - HALF_HEIGHT )},
                             player_info));
            world.add_back(player_ptr);
        }
        if (block == 'D' || block == 'E')
        {
            const int HALF_WIDTH{36};
            const int HALF_HEIGHT{64};

            door_pos = {static_cast<float>(( i % 10 * 128) + HALF_WIDTH ),
                        static_cast<float>(( 1 + (i / 10)) * 180 - HALF_HEIGHT )};
        }
        if (block == 'U' || block == 'H')
        {
            const int HALF_WIDTH{36};
            const int HALF_HEIGHT{64};

            upg_pillars_pos.push_back({static_cast<float>(( i % 10 * 128) + HALF_WIDTH ),
                                          static_cast<float>(( 1 + (i / 10)) * 180 - HALF_HEIGHT )});
        }

        if (i % 10 == 9)
        {
            f_stream.ignore(1000, '\n');
        }
    }

}

void Game_State::reset_world()
{
    player_info.exited_level = false;
    finished_level = false;
    enemies_spawned = 0;
    since_last_spawn = 0;
    upg_pillars_pos.clear();
    upg_pillars_pos.shrink_to_fit();
    world.clear_level();
}
