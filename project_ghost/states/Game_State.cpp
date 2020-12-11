//
// Created by jimte on 2020-12-11.
//

#include "Game_State.h"
#include "../game_objects/Enemy.h"

Game_State::Game_State(sf::RenderWindow &window)
:world(window)
{
    world.add_object(std::shared_ptr<Platform>(new Platform({700, 230}, "platform.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({700, 450}, "platform.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({200, 550}, "platform.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({500, 650}, "platform.png")));

    world.add_object(std::shared_ptr<Game_Object>(new Door({1000, 600}, "door.png")));
    world.add_object(std::shared_ptr<Game_Object>(new Player({500, 500}, "standing.png", 100, 100)));

    world.add_object(std::shared_ptr<Game_Object>(new Enemy({0, 0}, "enemy.png", 100, 0, world.get_player_ptr())));
    world.add_object(std::shared_ptr<Game_Object>(new Enemy({1000, 0}, "enemy.png", 100, 0, world.get_player_ptr())));
}

std::shared_ptr<State> Game_State::tick(sf::Time delta)
{


    world.tick(delta);
    return nullptr;
}

void Game_State::render(sf::RenderWindow &window)
{
    world.render(window);
}
