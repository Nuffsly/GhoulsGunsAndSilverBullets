//
// Created by marku849 on 2020-12-11.
//

#include "Upgrade.h"

Upgrade::Upgrade(std::map<std::string, int> int_changes, std::map<std::string, float> float_changes)
    : int_changes{int_changes}, float_changes{float_changes}
{}
