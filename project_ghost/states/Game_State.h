//
// Created by jimte on 2020-12-11.
//

#ifndef MAIN_CPP_GAME_STATE_H
#define MAIN_CPP_GAME_STATE_H

#include <memory>

#include "State.h"
#include "../managers/World.h"


class Game_State : public State
{
public:
    Game_State();

    std::shared_ptr<State> tick(sf::Time delta) override;

    void render(sf::RenderWindow &window) override;

private:
    World world;
};


#endif //MAIN_CPP_GAME_STATE_H
