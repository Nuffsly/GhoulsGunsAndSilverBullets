#include<SFML/Graphics.hpp>

#include "states/State.h"
#include "states/Menu_State.h"


int main()
{
    // Define the window to which we draw the game
    sf::RenderWindow window{sf::VideoMode(1280,720), "PROJECT: [G H 0 5 T]", sf::Style::Titlebar | sf::Style::Close};
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.setMouseCursorGrabbed(true);

    // Start the game loop with a main menu.
    State::run(window, std::make_shared<Menu_State>(window));

    return 0;
}