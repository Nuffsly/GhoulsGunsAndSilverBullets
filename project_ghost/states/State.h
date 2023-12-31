//
// Created by jimte on 2020-12-08.
//
//In this file:
//State
//Exit_State


#ifndef MAIN_CPP_STATE_H
#define MAIN_CPP_STATE_H

#include <SFML/Graphics.hpp>
#include <memory>

/**
 * \brief Abstract class that lays groundwork for all other states.
 * Also contains the main game loop.
 */
class State : public std::enable_shared_from_this<State>
{
public:
    virtual ~State() = default;

    virtual void on_key_press(sf::Keyboard::Key key);
    virtual void on_key_release(sf::Keyboard::Key key);

    virtual std::shared_ptr<State> tick(sf::Time time) = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    static void run(sf::RenderWindow &window, std::shared_ptr<State> state); /**<The main game loop. Uses whatever state that is active
 * and runs it.*/
};


/**
 * \brief Special case state for when the program should end.
 */
class Exit_State : public State
{
public:
    std::shared_ptr<State> tick (sf::Time) override;
    void render(sf::RenderWindow &window) override;
};

#endif //MAIN_CPP_STATE_H
