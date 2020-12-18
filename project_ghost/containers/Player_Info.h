//
// Created by marku849 on 2020-12-11.
//

#ifndef PROJECT_GHOST_PLAYER_INFO_H
#define PROJECT_GHOST_PLAYER_INFO_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Upgrade.h"

/**
 * \brief Support class that contains metadata about the player character.
 * Contains all data necessary to construct a new player along with some data that should be consistent through all levels.
 */
class Player_Info
{
public:
    Player_Info();

    int get_money() const;
    int get_score() const;
    int get_enemies_killed() const;
    std::vector<Upgrade> get_upgrades();

    void add_upgrade(Upgrade const& upgrade);
    void add_money(int change);
    void add_score(int change);
    void add_enemies_killed(int change);

    bool exited_level;
    bool is_alive;
    std::vector<std::string> bought_upgrades;

private:
    int money;
    int score;
    int enemies_killed;

    std::vector<Upgrade> gained_upgrades;
};


#endif //PROJECT_GHOST_PLAYER_INFO_H
