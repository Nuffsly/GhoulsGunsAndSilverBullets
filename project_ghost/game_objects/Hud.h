//
// Created by jimte on 2020-12-15.
//

#ifndef MAIN_CPP_HUD_H
#define MAIN_CPP_HUD_H

#include <SFML/Graphics.hpp>

/**
 * \brief Handles overlay displaying players current stats.
 */
class Hud
{
public:
    Hud();

    void draw_hud(sf::RenderWindow& window);

    void set_money(int);
    void set_health(int, int);
    void set_score(int);

private:
    sf::Text money_text;
    sf::Text health_text;
    sf::Text score_text;

    sf::Sprite health_icon;
    sf::Sprite money_icon;
};


#endif //MAIN_CPP_HUD_H
