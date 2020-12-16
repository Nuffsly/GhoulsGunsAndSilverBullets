//
// Created by marku849 on 2020-12-14.
//

#include <random>

#include "Money.h"
#include "../managers/Sound_Manager.h"


Money::Money(const sf::Vector2f &center, const std::string &texture_name)
        :Textured_Object(center, texture_name), timer{8.0}, falling{true}
{}

bool Money::update(sf::Time const& delta, World &world)
{
    if (falling)
    {
        fall(delta, world);
    }

    timer -= delta.asSeconds();

    // Make it blink before disappearing
    if (timer < 3 && (std::fmod(timer, 0.40) < 0.20 )
        && shape.getFillColor() == sf::Color::White)
    {
        shape.setFillColor(sf::Color(255, 255, 255, 0));
    }
    else if (shape.getFillColor() == sf::Color(255, 255, 255, 0)
               && fmod(timer, 0.40) > 0.20)
    {
        shape.setFillColor(sf::Color::White);
    }

    // Remove money when the timer is out
    if ( timer <= 0 )
    {
        return false;
    }

    return handle_collision(world);
}

void Money::fall(const sf::Time &delta, World &world)
{
    if (get_bottom() < world.stored_window.getSize().y)
    {
        const float SPEED{300};

        float clamped_position{get_position().x};

        const float low_clamp_x{get_size().x / 2};
        const float high_clamp_x{world.stored_window.getSize().x - (get_size().x / 2)};

        clamped_position = std::clamp(clamped_position, low_clamp_x, high_clamp_x);

        set_position({clamped_position, get_position().y + SPEED * delta.asSeconds()});
    }
    else
    {
        center.y = world.stored_window.getSize().y - shape.getSize().y/2;
        falling = false;
    }
}

bool Money::handle_collision(World &world)
{
    for (auto &collision : world.collides_with(*this))
    {
        if (dynamic_cast<Player *>(collision.get()))
        {
            std::random_device rd;
            std::uniform_int_distribution<int> uniform(20,27);

            dynamic_cast<Player *>(collision.get())->player_info.add_money(uniform(rd));

            Sound_Manager::play_sound("soul_pickup.wav");

            return false;
        }

        if (dynamic_cast<Platform *>(collision.get()) && falling)
        {
            const float MARGIN{5};

            if(get_bottom() > collision->get_top()
               && get_bottom() < collision->get_top() + MARGIN)
            {
                falling = false;
            }
        }
    }
    return true;
}