//
// Created by jimte on 2020-12-11.
//

#include "Game_State.h"
#include "../game_objects/Enemy.h"

Game_State::Game_State(sf::RenderWindow &window)
:world(window)
{
    world.add_object(std::shared_ptr<Platform>(new Platform({200, 550}, "platform.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({328, 550}, "platform.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({456, 550}, "platform.png")));

    world.add_object(std::shared_ptr<Platform>(new Platform({800, 550}, "platform.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({928, 550}, "platform.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({1056, 550}, "platform.png")));

    world.add_object(std::shared_ptr<Platform>(new Platform({630, 375}, "platform.png")));

    world.add_object(std::shared_ptr<Platform>(new Platform({200, 200}, "platform.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({328, 200}, "platform.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({456, 200}, "platform.png")));

    world.add_object(std::shared_ptr<Platform>(new Platform({800, 200}, "platform.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({928, 200}, "platform.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({1056, 200}, "platform.png")));


    world.add_object(std::shared_ptr<Game_Object>(new Door({1000, 650}, "door.png")));
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
