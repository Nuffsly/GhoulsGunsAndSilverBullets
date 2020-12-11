//
// Created by jimte on 2020-12-11.
//

#include "Game_State.h"

std::shared_ptr<State> Game_State::tick(sf::Time delta)
{
    world.tick(delta);
    return nullptr;
}

void Game_State::render(sf::RenderWindow &window)
{
    world.render(window);
}
