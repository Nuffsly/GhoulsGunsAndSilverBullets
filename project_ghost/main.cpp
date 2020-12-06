#include<SFML/Graphics.hpp>
#include "Textured_Object.h"
#include "Player.h"
#include "World.h"
#include "Enemy.h"

// Global constants
const int WIDTH{1000};
const int HEIGHT{1000};

void update(sf::RenderWindow &window);

int main()
{
    //Define our window
    sf::RenderWindow window{sf::VideoMode(WIDTH, HEIGHT), "PROJECT: [G H 0 5 T]"};
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    World world{};

    Platform platform{{500, 350}, "white.png"};
    Player player{{100, 100}, "standing.png", 100, 100};
    Enemy enemy{{0, 0}, "white.png", 100, 100, world.get_player_ptr()};

    world.add_object(std::make_shared<Player>(player));

    //world.add_object(std::make_shared<Player>(Player{{100, 100}, {100, 200}, 100, 100}));

    world.add_object(std::make_shared<Platform>(platform));
    word.add_object(std::make_shared<Enemy>(enemy))

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

