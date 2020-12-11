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

Player *Player_Info::create_new_player(sf::Vector2f const& center)
{
    int health{100};
    int damage{20};
    int max_jumps{1};

    float run_speed{100};
    float fire_rate{0.3};

    for (auto it{std::begin(gained_upgrades)};
         it != std::end(gained_upgrades); ++it)
    {
        if (it->float_changes.find("health") != std::end(it->float_changes))
        {
            health *= it->float_changes.at("health");
        }
        if (it->float_changes.find("damage") != std::end(it->float_changes))
        {
            damage *= it->float_changes.at("damage");
        }
        if (it->int_changes.find("max_jumps") != std::end(it->int_changes))
        {
            max_jumps += it->int_changes.at("max_jumps");
        }
        if (it->float_changes.find("run_speed") != std::end(it->float_changes))
        {
            run_speed *= it->float_changes.at("run_speed");
        }
        if (it->float_changes.find("fire_rate") != std::end(it->float_changes))
        {
            fire_rate *= it->float_changes.at("fire_rate");
        }
    }

    return new Player(center, "standing.png", health, damage, max_jumps, run_speed, fire_rate);
}
