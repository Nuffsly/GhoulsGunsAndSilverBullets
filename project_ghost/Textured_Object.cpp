//
// Created by jimte on 2020-12-02.
//

#include "Textured_Object.h"

Textured_Object::Textured_Object(sf::Vector2f center, sf::Vector2f size)
:Game_Object{center, {0,0}}
{
    shape.setSize({size.x, size.y});

    shape.setOrigin(size.x/2, size.y/2);
}

void Textured_Object::render(sf::RenderWindow &window)
{
    window.draw(shape);
}

Platform::Platform(sf::Vector2f center, sf::Vector2f size)
:Textured_Object{center, size}
{};