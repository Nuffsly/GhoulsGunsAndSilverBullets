//
// Created by marku849 on 2020-12-14.
//

#ifndef PROJECT_GHOST_UPGRADE_PILLAR_H
#define PROJECT_GHOST_UPGRADE_PILLAR_H

#include <SFML/Graphics.hpp>

#include "Textured_Object.h"
#include "../containers/Upgrade.h"

/**
 * \brief Object to contain Upgrade objects and assign them to the player if criteria is met.
 */
class Upgrade_Pillar : public Textured_Object
{
public:
    Upgrade_Pillar(const sf::Vector2f &center,
                   std::string const& texture_name,
                   Upgrade const& upgrade);

    bool update(const sf::Time &delta, World &world) override;

    void render(sf::RenderWindow &window) override;

    bool is_bought();

private:
    Upgrade upgrade;

    void setup_description();

    bool show_description;
    bool bought;

    sf::Text description;

};


#endif //PROJECT_GHOST_UPGRADE_PILLAR_H
