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

void Player_Info::add_money(int change)
{
    money += change;
}

void Player_Info::add_score(int change)
{
    score += change;
}

Player *Player_Info::create_new_player(sf::Vector2f center)
{
    return nullptr;
}
