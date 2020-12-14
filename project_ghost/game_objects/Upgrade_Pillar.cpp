//
// Created by marku849 on 2020-12-14.
//

#include "Upgrade_Pillar.h"

Upgrade_Pillar::Upgrade_Pillar(const sf::Vector2f &center,
                               std::string const& texture_name,
                               Upgrade const& upgrade)
        :Textured_Object{center, texture_name}, upgrade{upgrade}
{}

bool Upgrade_Pillar::update(const sf::Time &delta, World &world)
{
    return true;
}
