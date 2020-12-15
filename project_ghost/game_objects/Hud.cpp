//
// Created by jimte on 2020-12-15.
//

#include "Hud.h"
#include "../managers/Texture_Manager.h"


Hud::Hud()
{
    const std::string FONT{"pixel.ttf"};
    const int SIZE{25};
    const sf::Color COLOR{sf::Color::White};

    money_text.setFont(Font_Manager::get_font(FONT));
    health_text.setFont(Font_Manager::get_font(FONT));
    score_text.setFont(Font_Manager::get_font(FONT));

    money_text.setCharacterSize(SIZE);
    health_text.setCharacterSize(SIZE);
    score_text.setCharacterSize(SIZE);

    money_text.setFillColor(COLOR);
    health_text.setFillColor(COLOR);
    score_text.setFillColor(COLOR);

    money_text.setPosition(48, 35);
    health_text.setPosition(42, 0);
    score_text.setPosition(1270, 0);

    money_text.setString("0");
    health_text.setString("0/0");
    score_text.setString("0");

    health_icon.setTexture(*Texture_Manager::get_texture("icon_health.png"));
    health_icon.setPosition(10,0);

    money_icon.setTexture(*Texture_Manager::get_texture("money.png"));
    money_icon.setScale(2.5,2.5);
    money_icon.setPosition(10,35);
}

void Hud::draw_hud(sf::RenderWindow &window)
{
    sf::FloatRect score_bounds{score_text.getLocalBounds()};
    score_text.setPosition(1270 - score_bounds.width,
                           score_text.getPosition().y);

    window.draw(money_text);
    window.draw(health_text);
    window.draw(score_text);

    window.draw(health_icon);
    window.draw(money_icon);
}

void Hud::set_money(int money)
{
    money_text.setString(std::to_string(money));
}

void Hud::set_health(int health, int max_health)
{
    health_text.setString(std::to_string(health) + "/" + std::to_string(max_health));
}

void Hud::set_score(int score)
{
    score_text.setString("Score: " + std::to_string(score));
}
