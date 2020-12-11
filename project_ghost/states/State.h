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

class State
{
public:
    virtual ~State() = default;

    virtual void on_key_press(sf::Keyboard::Key key);
    virtual void on_key_release(sf::Keyboard::Key key);

    virtual std::shared_ptr<State> tick(sf::Time time) = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    static void run(sf::RenderWindow &window, std::shared_ptr<State> state);
};

class Exit_State : public State
{
public:
    std::shared_ptr<State> tick (sf::Time) override;
    void render(sf::RenderWindow &window) override;
};

#endif //MAIN_CPP_STATE_H
