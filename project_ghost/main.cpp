#include <iostream>
#include<SFML/Graphics.hpp>
#include "Textured_Object.h"
#include "Player.h"
#include "World.h"


void update(sf::RenderWindow &window);

int main()
{
    //Define our window
    sf::RenderWindow window{sf::VideoMode(1920, 1080), "PROJECT: [G H 0 5 T]"};
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    World world{};

    Platform platform{{500, 350},{100,20}};
    Player player{{100, 100}, {100, 200}, 100, 100};

    world.add_object(std::make_shared<Player>(player));

    //world.add_object(std::make_shared<Player>(Player{{100, 100}, {100, 200}, 100, 100}));

    world.add_object(std::make_shared<Platform>(platform));

    bool closed{false};

    sf::Clock clock;

    while (!closed)
    {
        sf::Event event{};

        window.clear();
        world.tick(clock.getElapsedTime());
        
        while (window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                        closed = true;
                        break;

                    default:
                        break;
                }
            }
        world.render(window);
        update(window);

    }

    return 0;
}

void update(sf::RenderWindow &window)
{
    //window.clear();
    window.display();
}

