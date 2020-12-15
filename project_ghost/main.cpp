#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "states/State.h"
#include "states/Game_State.h"

int main()
{
    //Define our window
    sf::RenderWindow window{sf::VideoMode(1280,720), "PROJECT: [G H 0 5 T]", sf::Style::Titlebar | sf::Style::Close};
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    //window.setMouseCursorGrabbed(true);
    //window.setMouseCursorVisible(false);

    //Start playing BG music
    sf::Music music{};
    if(!music.openFromFile("../audio_data/background_music.wav"))
    {
        throw std::logic_error("Failed to load background music.");
    }
    music.setLoop(true);
    music.setVolume(25);
    music.play();

    State::run(window, std::make_shared<Game_State>(window));

    return 0;
}