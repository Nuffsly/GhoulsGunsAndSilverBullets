//
// Created by jimte on 2020-12-08.
//
//In this file:
//State
//Exit_State

#include "State.h"

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
                    if(event.key.code == sf::Keyboard::Escape)
                    {return;}

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
{}
