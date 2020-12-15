//
// Created by jimte on 2020-12-15.
//

#include "Menu_State.h"
#include "Game_State.h"
#include "../managers/Texture_Manager.h"

Menu_State::Menu_State(sf::RenderWindow &window, std::shared_ptr<State> resume)
:selected{0}, enter_pressed{false}, delay{sf::milliseconds(300)}
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
    menu_items.push_back({ sf::Text{text, font, 60}, 0.0f, action});
}

void Menu_State::on_key_press(sf::Keyboard::Key key)
{
    switch (key)
    {
        case sf::Keyboard::Down:
            if (selected + 1 < menu_items.size())
            {
                selected++;
            }
            break;

        case sf::Keyboard::Up:
            if (selected > 0)
            {
                selected--;
            }
            break;

        case sf::Keyboard::Return:
            enter_pressed = true;
            break;

        default:
            break;
    }
}

std::shared_ptr<State> Menu_State::tick(sf::Time time)
{
    float diff = float(time.asMicroseconds()) / float(delay.asMicroseconds());

    for (size_t i = 0; i < menu_items.size(); i++)
    {
        Menu_Item &item = menu_items[i];

        if (i == selected)
        {
            item.state += diff;
            if (item.state > 1.0f)
                item.state = 1.0f;
        } else
        {
            item.state -= diff;
            if (item.state < 0.0f)
                item.state = 0.0f;
        }
    }

    if (enter_pressed)
        return menu_items[selected].action();
    else
        return nullptr;
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

        int state = static_cast<int>(255 * item.state);
        item.text.setFillColor(sf::Color(state, 255, state));
        window.draw(item.text);
    }
}

void Menu_State::on_key_release(sf::Keyboard::Key key)
{}

