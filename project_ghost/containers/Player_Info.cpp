//
// Created by marku849 on 2020-12-11.
//

#include "Player_Info.h"

Player_Info::Player_Info()
    :exited_level{false}, is_alive{true}, money{0}, score{0}, enemies_killed{0}
{}

int Player_Info::get_money() const
{
    return money;
}

int Player_Info::get_score() const
{
    return score;
}

int Player_Info::get_enemies_killed() const
{
    return enemies_killed;
}

std::vector<Upgrade> Player_Info::get_upgrades()
{
    return gained_upgrades;
}

void Player_Info::add_upgrade(const Upgrade &upgrade)
{
    bought_upgrades.push_back(upgrade.name);
    gained_upgrades.push_back(upgrade);
}

void Player_Info::add_money(int change)
{
    money += change;
}

void Player_Info::add_score(int change)
{
    score += change;
}

void Player_Info::add_enemies_killed(int change)
{
    enemies_killed += change;
}



