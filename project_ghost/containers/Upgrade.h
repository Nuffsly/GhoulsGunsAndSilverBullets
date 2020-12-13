//
// Created by marku849 on 2020-12-11.
//

#ifndef PROJECT_GHOST_UPGRADE_H
#define PROJECT_GHOST_UPGRADE_H

#include <map>


struct Upgrade
{
    explicit Upgrade(std::string const& name);

    std::string name;
    std::string description;
    int price;

    std::map<std::string, int> int_changes;
    std::map<std::string, float> float_changes;
};


#endif //PROJECT_GHOST_UPGRADE_H
