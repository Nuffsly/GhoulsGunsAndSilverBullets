//
// Created by jimte on 2020-12-11.
//

#ifndef MAIN_CPP_GAME_STATE_H
#define MAIN_CPP_GAME_STATE_H

#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <vector>
#include <string>

#include "State.h"
#include "../containers/Upgrade.h"
#include "../containers/Player_Info.h"
#include "../managers/World.h"
#include "../game_objects/Player.h"
#include "../game_objects/Enemy.h"

class Game_Object;

/**
 * \brief Handles most overarching game functions like levels and score.
 * Keeps track of all things that concern the level as a whole like where and when to spawn objects.
 * Owns a world in which all the objects can interact and react to another.
 */

class Game_State : public State
{
public:
    explicit Game_State(sf::RenderWindow &window);
    Game_State() = delete;

    std::shared_ptr<State> tick(sf::Time delta) override; /**<Performs all the logical subroutines that are required for the game to function.*/
    void render(sf::RenderWindow &window) override; /**<Draws all relevant shapes to the screen */

    void spawn_lvl_end_stuff();
    void spawn_enemy();
    void reset_world();

private:
    Player_Info player_info;
    World world;
    std::vector<Upgrade> available_upgrades;
    std::shared_ptr<Game_Object> player_ptr;
    int level;
    int platforms_on_level;
    bool finished_level;
    int enemies_spawned;
    int total_enemies_spawned;
    float since_last_spawn;
    sf::Vector2f door_pos;
    std::vector<sf::Vector2f> upg_pillars_pos;
    sf::Music music;
    sf::Sprite background;
    float sec_since_last_frame;
    std::vector<int> frame_numbers;

    void load_level();
    void load_upgrades();
    void draw_background(std::string filename);
};


class Game_Over_State : public State
{
public:
    Game_Over_State(sf::RenderWindow &window, int score, int level);
private:
    std::shared_ptr<State> tick(sf::Time time) override;
    void render(sf::RenderWindow &window) override;

    sf::RenderWindow &window;

    int score;
    int level;

    sf::Music game_over_sound;
};

#endif //MAIN_CPP_GAME_STATE_H
