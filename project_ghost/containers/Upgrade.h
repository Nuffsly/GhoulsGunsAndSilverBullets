//
// Created by marku849 on 2020-12-11.
//

#ifndef PROJECT_GHOST_UPGRADE_H
#define PROJECT_GHOST_UPGRADE_H

#include <map>


struct Upgrade
{
    Upgrade(std::map<std::string, int> int_changes, std::map<std::string, float> float_changes);

    std::map<std::string, int> int_changes;
    std::map<std::string, float> float_changes;
};


#endif //PROJECT_GHOST_UPGRADE_H
