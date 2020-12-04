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
#include <memory>

class World
{
public:
    void tick(sf::Time);

    void render(sf::RenderWindow &window);

    bool load_level(std::string file_name);

    void add_object(std::shared_ptr<Game_Object> game_object);

private:
    std::vector<std::shared_ptr<Game_Object>> game_objects;
};


#endif //MAIN_CPP_WORLD_H
