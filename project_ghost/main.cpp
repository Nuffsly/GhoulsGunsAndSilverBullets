#include <iostream>
#include<SFML/Graphics.hpp>
#include "Textured_Object.h"
#include "Player.h"

void update(sf::RenderWindow &window);

int main()
{
    //Define our window
    sf::RenderWindow window{sf::VideoMode(1920, 1080), "HelloWorld!"};
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    Platform platform{{500, 350},{100,20}};
    Player player{{100, 100}, {100, 200}, 100, 100};

    bool closed{false};

    sf::Clock clock;

    while (!closed)
    {
        sf::Event event{};

        window.clear();
        player.update(clock.getElapsedTime());
        
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
        player.render(window);
        platform.render(window);
        update(window);

    }

    return 0;
}

void update(sf::RenderWindow &window)
{
    //window.clear();
    window.display();
}

