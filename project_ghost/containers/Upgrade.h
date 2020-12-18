//
// Created by marku849 on 2020-12-11.
//

#ifndef PROJECT_GHOST_UPGRADE_H
#define PROJECT_GHOST_UPGRADE_H

#include <map>

/**
 * \brief Contains data that can be applied to a player object.
 * This will affect certain stats depending on the content.
 */
struct Upgrade
{
    explicit Upgrade(std::string const& name);

    std::string name;
    std::string description;
    int price;

    std::map<std::string, float> number_changes;
};


#endif //PROJECT_GHOST_UPGRADE_H
