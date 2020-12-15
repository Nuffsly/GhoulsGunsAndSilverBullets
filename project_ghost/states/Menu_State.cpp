//
// Created by jimte on 2020-12-15.
//

#include "Menu_State.h"
#include "Game_State.h"
#include "../managers/Texture_Manager.h"

Menu_State::Menu_State(sf::RenderWindow &window, std::shared_ptr<State> resume)
:selected{0}, enter_pressed{false}
{
    font = Font_Manager::get_font("pixel.ttf");

    if(resume)
    {
        add("Resume", [resume](){ return resume; });
        background = resume;
    }

    add("New Game", [&window](){ return std::make_shared<Game_State>(window); });
    add("Exit", [](){ return std::make_shared<Exit_State>(); });
}

void Menu_State::add(const std::string &text, Menu_State::Action action)
{
    menu_items.push_back({ sf::Text{text, font, 120}, false, action});
}

void Menu_State::on_key_press(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::Down || key == sf::Keyboard::S)
    {
        if (selected + 1 < menu_items.size())
        {
            selected++;
        }
    } else if (key == sf::Keyboard::Up || key == sf::Keyboard::W)
    {
        if (selected > 0)
        {
            selected--;
        }
    } else if (key == sf::Keyboard::Return)
    {
        enter_pressed = true;
    }
}

std::shared_ptr<State> Menu_State::tick(sf::Time time)
{
    for (size_t i = 0; i < menu_items.size(); i++)
    {
        Menu_Item &item = menu_items[i];

        if (i == selected)
        {
            item.state = true;
        } else
        {
            item.state = false;
        }
    }

    if (enter_pressed)
    {
        return menu_items[selected].action();
    }
    else
    {
        return nullptr;
    }
}

void Menu_State::render(sf::RenderWindow &window)
{
    if (background)
    {
        background->render(window);
    }

    float y{100};
    auto windowSize = window.getSize();

    for (auto &item : menu_items)
    {
        auto bounds = item.text.getLocalBounds();
        item.text.setPosition((windowSize.x - bounds.width) / 2, y);
        y += bounds.height * 2.0f;

        if(item.state)
        {
            item.text.setOutlineColor(sf::Color::Red);
            item.text.setOutlineThickness(5);
        } else
        {
            item.text.setOutlineThickness(0);
        }
        window.draw(item.text);
    }
}

void Menu_State::on_key_release(sf::Keyboard::Key key)
{}

