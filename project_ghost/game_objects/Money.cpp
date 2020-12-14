//
// Created by marku849 on 2020-12-14.
//

#include "Money.h"

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

        set_position({get_position().x, get_position().y + SPEED * delta.asSeconds()});
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
            // TODO: Add to players money
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