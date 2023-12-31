//
// Created by jimte on 2020-12-11.
//

#include <cmath>
#include <random>
#include <filesystem>

#include "Game_State.h"
#include "../game_objects/Upgrade_Pillar.h"
#include "../game_objects/Door.h"
#include "Menu_State.h"


Game_State::Game_State(sf::RenderWindow &window)
    : player_info{}, world(window), available_upgrades{}, level{1},
      finished_level{false}, enemies_spawned{0}, total_enemies_spawned{0},
      since_last_spawn{0}, platforms_on_level{0},
      sec_since_last_frame{0},
      frame_numbers{0, 320, 640, 960, 1280, 1600, 1920, 2240}
{
    //Start playing BG music
    if(!music.openFromFile("../audio_data/background_music.wav"))
    {
        throw std::logic_error("Failed to load background music.");
    }
    music.setLoop(true);
    music.setVolume(25);
    music.play();

    load_upgrades();

    load_level();
}

std::shared_ptr<State> Game_State::tick(sf::Time delta)
{
    world.tick(delta);
    sec_since_last_frame += delta.asSeconds();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        return std::make_shared<Menu_State>(world.stored_window, shared_from_this());
    }

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
        spawn_lvl_end_stuff();
    }

    if (player_info.exited_level)
    {
        reset_world();
        level += 1;
        load_level();
    }

    if ( !player_info.is_alive )
    {
        return std::make_shared<Game_Over_State>(world.stored_window, player_info.get_score(), level);
    }

    return nullptr;
}

void Game_State::render(sf::RenderWindow &window)
{
    draw_background("hallway.png");
    world.render(window);
}

void Game_State::spawn_enemy()
{
    if (since_last_spawn > 2.0f * ( 1 - level * 0.10 ) && enemies_spawned < 9 + pow(level, 1.3) )
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
                          "enemy.png", 19 * ( 1 + level * 0.06 ),
                          15*(1 + level * 0.10 ), player_ptr)));
        enemies_spawned += 1;
        total_enemies_spawned += 1;
        since_last_spawn = 0;
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
    const int NUMBER_OF_LEVELS{10};

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

        if (block == '_' || block == 'B' || block == 'E' || block == 'H')
        {
            const int HALF_WIDTH{64};

            world.add_front(std::shared_ptr<Game_Object>(
                    new Platform(
                            {static_cast<float>(( i % 10 * 128) + HALF_WIDTH ),
                             static_cast<float>(( 1 + (i / 10)) * 180 )},
                            "platform.png")));
            platforms_on_level += 1;
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

void Game_State::spawn_lvl_end_stuff()
{
    std::random_device rd;

    for (sf::Vector2f &pillar_pos : upg_pillars_pos)
    {
        std::uniform_int_distribution<int> uniform(0,available_upgrades.size()-1);
        int i{uniform(rd)};

        world.insert_at(std::shared_ptr<Game_Object>(
                new Upgrade_Pillar(pillar_pos,
                                   "upgrade.png",
                                   available_upgrades[i])), platforms_on_level);
    }

    world.add_front(std::shared_ptr<Game_Object>(
            new Door( door_pos, "door.png") ));
    door_pos = {0, 0};
}

void Game_State::reset_world()
{
    player_info.exited_level = false;
    finished_level = false;
    enemies_spawned = 0;
    since_last_spawn = 0;
    upg_pillars_pos.clear();
    upg_pillars_pos.shrink_to_fit();

    for  ( std::string &bought_upgrade : player_info.bought_upgrades )
    {
        for ( Upgrade &upgrade : available_upgrades )
        {
            if ( bought_upgrade == upgrade.name )
            {
                upgrade.price *= 1.2;
            }
        }
    }
    player_info.bought_upgrades.clear();
    player_info.bought_upgrades.shrink_to_fit();
    platforms_on_level = 0;

    world.clear_level();
}

void Game_State::draw_background(std::string filename)
{
    if(sec_since_last_frame > 0.2)
    {
        std::rotate(frame_numbers.begin(), frame_numbers.begin()+1, frame_numbers.end());
        sec_since_last_frame = 0;
    }

    background.setTexture(*Texture_Manager::get_texture(filename));
    sf::IntRect frame{frame_numbers[0], 0, 320, 180};
    background.setTextureRect(frame);

    background.setScale(4,4);

    world.stored_window.draw(background);
}

// Game_Over_State
Game_Over_State::Game_Over_State(sf::RenderWindow &window, int score, int level)
:window{window}, score{score}, level{level}, game_over_sound{}
{
    if(!game_over_sound.openFromFile("../audio_data/game_over.wav"))
    {
        throw std::logic_error("Failed to load game_over music.");
    }
    game_over_sound.setLoop(true);
    game_over_sound.play();
}

std::shared_ptr<State> Game_Over_State::tick(sf::Time time)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        return std::make_shared<Menu_State>(window);
    }
    return nullptr;
}

void Game_Over_State::render(sf::RenderWindow &window)
{
    sf::Text game_over;
    game_over.setFont(Font_Manager::get_font("pixel.ttf"));
    game_over.setCharacterSize(200);
    game_over.setStyle(sf::Text::Bold);
    game_over.setString("GAME OVER");
    game_over.setFillColor(sf::Color::White);

    game_over.setPosition(100, 100);

    sf::Text score_display;
    score_display.setFont(Font_Manager::get_font("pixel.ttf"));
    score_display.setCharacterSize(75);
    score_display.setString("   Score: " + std::to_string(score) + "\nLevel reached: " + std::to_string(level));
    score_display.setFillColor(sf::Color::White);

    score_display.setPosition(300, game_over.getGlobalBounds().top + game_over.getGlobalBounds().height + 25);

    sf::Text info;
    info.setFont(Font_Manager::get_font("pixel.ttf"));
    info.setCharacterSize(75);
    info.setString("Press [E] to continue");
    info.setFillColor(sf::Color::White);

    info.setPosition(175, 600);

    window.draw(game_over);
    window.draw(score_display);
    window.draw(info);
}

