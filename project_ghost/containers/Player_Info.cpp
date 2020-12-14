//
// Created by marku849 on 2020-12-11.
//

#include "Player_Info.h"

int Player_Info::get_money() const
{
    return money;
}

int Player_Info::get_score() const
{
    return score;
}

std::vector<Upgrade> Player_Info::get_upgrades()
{
    return gained_upgrades;
}

void Player_Info::add_upgrade(const Upgrade &upgrade)
{
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