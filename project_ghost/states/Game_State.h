//
// Created by jimte on 2020-12-11.
//

#ifndef MAIN_CPP_GAME_STATE_H
#define MAIN_CPP_GAME_STATE_H

#include<SFML/Graphics.hpp>
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

class Game_State : public State
{
public:
    explicit Game_State(sf::RenderWindow &window);
    Game_State() = delete;

    std::shared_ptr<State> tick(sf::Time delta) override;
    void render(sf::RenderWindow &window) override;

    void spawn_enemy();

private:
    Player_Info player_info;
    World world;
    std::vector<Upgrade> available_upgrades;
    std::shared_ptr<Game_Object> player_ptr;
    int level;
    bool finished_level;
    int enemies_spawned;
    float since_last_spawn;
    sf::Vector2f door_pos;
    std::vector<sf::Vector2f> upg_pillars_pos;

    void load_level();
    void load_upgrades();
};


#endif //MAIN_CPP_GAME_STATE_H
