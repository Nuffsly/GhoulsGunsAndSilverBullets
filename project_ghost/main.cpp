#include<SFML/Graphics.hpp>
#include "game_objects/Textured_Object.h"
#include "game_objects/Player.h"
#include "managers/World.h"
#include "game_objects/Enemy.h"

// Global constants
const int WIDTH{1280};
const int HEIGHT{720};

int main()
{
    //Define our window
    sf::RenderWindow window{sf::VideoMode(WIDTH, HEIGHT), "PROJECT: [G H 0 5 T]", sf::Style::Fullscreen};
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(30);
    window.setKeyRepeatEnabled(false);

    World world{};

    //Platform platform{{500, 650}, "white.png"};
    world.add_object(std::shared_ptr<Game_Object>(new Player({500, 500}, "standing.png", 100, 100)));

    world.add_object(std::shared_ptr<Platform>(new Platform({1000, 300}, "white.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({800, 450}, "white.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({200, 550}, "white.png")));
    world.add_object(std::shared_ptr<Platform>(new Platform({500, 650}, "white.png")));
    world.add_object(std::shared_ptr<Game_Object>(new Enemy({0, 0}, "enemy.png", 100, 100, world.get_player_ptr())));
    world.add_object(std::shared_ptr<Game_Object>(new Enemy({500, 500}, "enemy.png", 100, 100, world.get_player_ptr())));

    bool closed{false};

    sf::Clock clock;

    while (!closed)
    {
        sf::Event event{};

        window.clear();
        world.tick(clock.restart());
        
        while (window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                        closed = true;
                        break;
                    case sf::Event::KeyPressed:
                        if (event.key.code == sf::Keyboard::Escape)
                        {
                            closed = true;
                            break;
                        }
                    default:
                        break;
                }
            }
        world.render(window);
        window.display();

    }

    return 0;
}