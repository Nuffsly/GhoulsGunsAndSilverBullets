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

    money_text.setPosition(0, 35);
    health_text.setPosition(0, 0);
    score_text.setPosition(0, 70);

    money_text.setString("0");
    health_text.setString("0/0");
    score_text.setString("0");
}

void Hud::draw_hud(sf::RenderWindow &window)
{
    window.draw(money_text);
    window.draw(health_text);
    window.draw(score_text);
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
    score_text.setString(std::to_string(score));
}
