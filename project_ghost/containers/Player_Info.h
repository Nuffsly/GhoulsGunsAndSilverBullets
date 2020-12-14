//
// Created by marku849 on 2020-12-11.
//

#ifndef PROJECT_GHOST_PLAYER_INFO_H
#define PROJECT_GHOST_PLAYER_INFO_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Upgrade.h"

class Player_Info
{
public:
    Player_Info() = default;

    bool exited_level;

    int get_money() const;
    int get_score() const;
    int get_enemies_killed() const;

    std::vector<Upgrade> get_upgrades();

    void add_upgrade(Upgrade const& upgrade);
    void add_money(int change);
    void add_score(int change);
    void add_enemies_killed(int change);

private:
    int money;
    int score;
    int enemies_killed;

    std::vector<Upgrade> gained_upgrades;
};


#endif //PROJECT_GHOST_PLAYER_INFO_H
