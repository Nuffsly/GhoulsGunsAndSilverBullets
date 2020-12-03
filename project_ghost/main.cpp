#include <iostream>
#include<SFML/Graphics.hpp>
#include "Textured_Object.h"

void update(sf::RenderWindow &window);

void movePlayer(sf::Shape &player, sf::Vector2f &position);

int main()
{
    //Define our window
    sf::RenderWindow window{sf::VideoMode(1024, 768), "HelloWorld!"};
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    Platform platform{{500, 350},{100,20}};

    bool closed{false};
    sf::RectangleShape rectangle(sf::Vector2f(50, 100));
    rectangle.setOrigin(25, 50);
    sf::Vector2f rectanglePos(20, 20);

    sf::Clock clock;

    while (!closed)
    {
        sf::Event event{};

        window.clear();
        movePlayer(rectangle, rectanglePos);
        
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
        window.draw(rectangle);
        update(window);

    }

    return 0;
}

void update(sf::RenderWindow &window)
{
    //window.clear();
    window.display();
}

void movePlayer(sf::Shape &player, sf::Vector2f &position)
{
    sf::Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;

    player.setPosition(position += direction);
}