//
// Created by jimte on 2020-12-02.
//

#include "Game_Object.h"

Game_Object::Game_Object(const sf::Vector2f &center, const sf::Vector2f &hitbox)
:center{center}, hitbox{hitbox}
{}

float Game_Object::get_right() const
{
    return center.x + hitbox.x / 2;
}

float Game_Object::get_left() const
{
    return center.x - hitbox.x / 2;
}

float Game_Object::get_top() const
{
    return center.y - hitbox.y / 2;
}

float Game_Object::get_bottom() const
{
    return center.y + hitbox.y / 2;
}