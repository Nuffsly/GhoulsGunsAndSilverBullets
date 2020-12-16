#include<SFML/Graphics.hpp>

#include "states/State.h"
#include "states/Menu_State.h"

int main()
{
    //Define our window
    sf::RenderWindow window{sf::VideoMode(1280,720), "PROJECT: [G H 0 5 T]", sf::Style::Titlebar | sf::Style::Close};
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    //window.setMouseCursorGrabbed(true);
    //window.setMouseCursorVisible(false);

    State::run(window, std::make_shared<Menu_State>(window));

    return 0;
}