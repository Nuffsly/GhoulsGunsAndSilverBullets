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
{
    setup_description();
}

bool Upgrade_Pillar::update(const sf::Time &delta, World &world)
{
    show_description = false;

    for (auto &collision : world.collides_with(*this))
    {
        if (dynamic_cast<Player *>(collision.get()))
        {
            show_description = true;

            Player* player{dynamic_cast<Player *>(collision.get())};

            if ( sf::Keyboard::isKeyPressed( sf::Keyboard::E )
                && !bought
                && player->player_info.get_money() >= upgrade.price)
            {
                bought = true;
                player->player_info.add_money( -upgrade.price );
                player->player_info.add_upgrade(upgrade);
                // TODO: Stoppa in saker som ska hända när man köper tex ljud
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

    /*
    if (bought)
    {
        //TODO: Stoppa in saker som ska rendereas alltid när uppgradering är köpt
    }*/
}

void Upgrade_Pillar::setup_description()
{
    const std::string FONT{"pixel.ttf"};
    const int SIZE{25};
    const sf::Color COLOR{sf::Color::White};
    const float MARGIN{10};

    description.setFont(Font_Manager::get_font(FONT));

    description.setCharacterSize(SIZE);

    description.setFillColor(COLOR);

    description.setString(upgrade.name + '\n'
                            + upgrade.description + '\n'
                            + "Price: " + std::to_string(upgrade.price) );

    description.setPosition(center.x-description.getLocalBounds().width/2, get_top()-description.getLocalBounds().height-MARGIN);


}
