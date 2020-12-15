//
// Created by marku849 on 2020-12-14.
//

#include "Upgrade_Pillar.h"
#include "../managers/World.h"
#include "Player.h"

Upgrade_Pillar::Upgrade_Pillar(const sf::Vector2f &center,
                               std::string const& texture_name,
                               Upgrade const& upgrade)
        :Textured_Object{center, texture_name}, upgrade{upgrade},
        show_description{false}, bought{false}
{}

bool Upgrade_Pillar::update(const sf::Time &delta, World &world)
{
    show_description = false;

    for (auto &collision : world.collides_with(*this))
    {
        if (dynamic_cast<Player *>(collision.get()))
        {
            show_description = true;

            if ( sf::Keyboard::isKeyPressed( sf::Keyboard::E ) && !bought)
            {
                // TODO: Stoppa in saker som ska hända när man köper
                bought = true;
            }
        }
    }
    return true;
}

void Upgrade_Pillar::render(sf::RenderWindow &window)
{
    Textured_Object::render(window);

    if (show_description && !bought)
    {
        window.draw(description);
    }

    if (bought)
    {
        //TODO: Stoppa in saker som ska rendereas alltid när uppgradering är köpt
    }
}

Upgrade Upgrade_Pillar::get_upgrade() const
{
    return upgrade;
}
