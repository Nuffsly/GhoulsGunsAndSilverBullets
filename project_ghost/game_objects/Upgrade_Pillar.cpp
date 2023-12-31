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
    //Fix hitbox. Can't use base because of animations
    const float SCALE{4};

    sf::Vector2f size{shape.getTexture()->getSize()};

    size = {size.x/2 * SCALE, size.y * SCALE};
    sf::IntRect texture_rect{0, 0, 32, 32};

    hitbox = size;
    shape.setTextureRect(texture_rect);
    shape.setSize(size);
    shape.setOrigin(size.x/2, size.y/2);
    shape.setPosition(center);

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

                // Change texture
                sf::IntRect texture_rect{32, 0, 32, 32};
                shape.setTextureRect(texture_rect);
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
}

void Upgrade_Pillar::setup_description()
{
    const std::string FONT{"pixel.ttf"};
    const int SIZE{25};
    const sf::Color FILL_COLOR{sf::Color::White};
    const sf::Color OUTLINE_COLOR{sf::Color::Black};
    const float MARGIN{40};

    description.setFont(Font_Manager::get_font(FONT));
    description.setCharacterSize(SIZE);
    description.setFillColor(FILL_COLOR);
    description.setOutlineColor(OUTLINE_COLOR);
    description.setOutlineThickness(2);

    description.setString(upgrade.name + '\n'
                            + "Souls: " + std::to_string(upgrade.price) + '\n'
                            + '\n'
                            + upgrade.description );

    float clamped_x{std::clamp((center.x - description.getLocalBounds().width / 2),
                               0.0f,
                               (1280 - description.getLocalBounds().width))};

    float clamped_y{std::clamp( (get_top() - description.getLocalBounds().height
                               - MARGIN),
                               0.0f,
                               (1280 - description.getLocalBounds().height) ) };

    description.setPosition( clamped_x, clamped_y );


}

bool Upgrade_Pillar::is_bought()
{
    return bought;
}
