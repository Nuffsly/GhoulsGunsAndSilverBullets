//
// Created by jimte on 2020-12-08.
//
//In this file:
//State
//Exit_State

#include <thread>

#include "State.h"
#include "../managers/Texture_Manager.h"

void State::on_key_press(sf::Keyboard::Key key)
{}

void State::on_key_release(sf::Keyboard::Key key)
{}

void State::run(sf::RenderWindow &window, std::shared_ptr<State> state)
{
    sf::Clock clock;

    while(state)
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    return;

                case sf::Event::KeyPressed:
                    state->on_key_press(event.key.code);
                    break;

                case sf::Event::KeyReleased:
                    state->on_key_release(event.key.code);
                    break;

                default:
                    break;
            }
        }

        window.clear();

        // If Tick returns a new state switch to using that.
        // Unless it is Exit_State, then we stop the function.
        if(auto new_state{state->tick(clock.restart())})
        {
            if (std::dynamic_pointer_cast<Exit_State>(new_state))
            {
                new_state->render(window);
                return;
            }
            else
            {
                state = new_state;
            }
            continue;
        }

        state->render(window);
        window.display();
    }
}


// Exit_State
std::shared_ptr<State> Exit_State::tick(sf::Time)
{
    return nullptr;
}

void Exit_State::render(sf::RenderWindow &window)
{
    sf::Text game_over;
    game_over.setFont(Font_Manager::get_font("pixel.ttf"));
    game_over.setCharacterSize(200);
    game_over.setStyle(sf::Text::Bold);
    game_over.setString("GAME OVER");
    game_over.setFillColor(sf::Color::White);

    game_over.setPosition(100, 250);

    window.draw(game_over);
    window.display();
    std::this_thread::sleep_for(std::chrono::seconds(4));
}
