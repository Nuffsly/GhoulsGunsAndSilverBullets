//
// Created by jimte on 2020-12-11.
//

#ifndef MAIN_CPP_GAME_STATE_H
#define MAIN_CPP_GAME_STATE_H

#include <memory>
#include <vector>

#include "State.h"
#include "../managers/World.h"
#include "../containers/Player_Info.h"
#include "../containers/Upgrade.h"


class Game_State : public State
{
public:
    explicit Game_State(sf::RenderWindow &window);
    Game_State() = delete;

    std::shared_ptr<State> tick(sf::Time delta) override;
    void render(sf::RenderWindow &window) override;

    void spawn_enemy();

private:
    World world;
    Player_Info player_info;
    std::vector<Upgrade> available_upgrades;
    int level;
    bool finished_level;
    int enemies_spawned;
    float since_last_spawn;

    void load_upgrades();
};


#endif //MAIN_CPP_GAME_STATE_H
