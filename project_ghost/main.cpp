#include<SFML/Graphics.hpp>
#include "states/State.h"
#include "states/Game_State.h"

// Global constants
const int WIDTH{1280};
const int HEIGHT{720};

int main()
{
    //Define our window
    sf::RenderWindow window{sf::VideoMode(WIDTH, HEIGHT), "PROJECT: [G H 0 5 T]"};
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    State::run(window, std::make_shared<Game_State>(window));

    return 0;
}