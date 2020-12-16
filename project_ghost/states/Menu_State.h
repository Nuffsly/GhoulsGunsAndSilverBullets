//
// Created by jimte on 2020-12-15.
//

#ifndef MAIN_CPP_MENU_STATE_H
#define MAIN_CPP_MENU_STATE_H

#include <memory>
#include <vector>
#include <functional>

#include "State.h"

class Menu_State : public State
{
public:
    Menu_State(sf::RenderWindow &window, std::shared_ptr<State> resume = nullptr);

    void on_key_press(sf::Keyboard::Key key) override;
    void on_key_release(sf::Keyboard::Key key) override;

    std::shared_ptr<State> tick(sf::Time time) override;
    void render(sf::RenderWindow &window) override;

private:
    using Action = std::function<std::shared_ptr<State>()>;

    struct Menu_Item
    {
        sf::Text text;

        bool state;

        Action action;
    };

    sf::Font font;

    std::vector<Menu_Item> menu_items;

    size_t selected;

    bool enter_pressed;

    std::shared_ptr<State> background;

    void add(std::string const& text, Action action);
};




#endif //MAIN_CPP_MENU_STATE_H
