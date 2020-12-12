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
    // Default Values
    std::map<std::string, float> player_stats_float{
        {"run_speed*", 100},
        {"fire_rate*", 0.3}
    };
    std::map<std::string, int> player_stats_int{
        {"health*",    100},
        {"damage*",    20},
        {"max_jumps+", 1}
    };

    for (auto it{std::begin(gained_upgrades)};
         it != std::end(gained_upgrades); ++it)
    {
        for (auto it2{std::begin(it->int_changes)};
             it2 != std::end(it->int_changes); ++it2)
        {
            if (it2->first.back() == '+')
            {
                player_stats_int[it2->first] += it2->second;
            }
            if (it2->first.back() == '*')
            {
                player_stats_int[it2->first] *= it2->second;
            }
            if (it2->first.back() == '=')
            {
                player_stats_int[it2->first] = it2->second;
            }
        }
        for (auto it2{std::begin(it->float_changes)};
             it2 != std::end(it->float_changes); ++it2)
        {
            if (it2->first.back() == '+')
            {
                player_stats_int[it2->first] += it2->second;
            }
            if (it2->first.back() == '*')
            {
                player_stats_int[it2->first] *= it2->second;
            }
            if (it2->first.back() == '=')
            {
                player_stats_int[it2->first] = it2->second;
            }
        }
    }

    return new Player(center, "standing.png",
                      player_stats_int["health*"],
                      player_stats_int["damage*"],
                      player_stats_int["max_jumps+"],
                      player_stats_float["run_speed*"],
                      player_stats_float["fire_rate*"]);
}
