//
// Created by marku849 on 2020-12-14.
//

#ifndef PROJECT_GHOST_UPGRADE_PILLAR_H
#define PROJECT_GHOST_UPGRADE_PILLAR_H

#include <SFML/Graphics.hpp>

#include "Textured_Object.h"
#include "../containers/Upgrade.h"

class Upgrade_Pillar : public Textured_Object
{
public:
    Upgrade_Pillar(const sf::Vector2f &center,
                   std::string const& texture_name,
                   Upgrade const& upgrade);
    bool update(const sf::Time &delta, World &world) override;

private:
    Upgrade upgrade;

};


#endif //PROJECT_GHOST_UPGRADE_PILLAR_H
