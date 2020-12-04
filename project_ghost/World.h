//
// Created by jimte on 2020-12-04.
//

#ifndef MAIN_CPP_WORLD_H
#define MAIN_CPP_WORLD_H

#include "Game_Object.h"
#include "Textured_Object.h"

#include<SFML/Graphics.hpp>
#include <vector>
#include <string>

class World
{
public:
    void tick(sf::Time);

    void render(sf::RenderWindow &window);

    bool load_level(std::string file_name);

private:
    std::vector<Game_Object> game_objects;
};


#endif //MAIN_CPP_WORLD_H
