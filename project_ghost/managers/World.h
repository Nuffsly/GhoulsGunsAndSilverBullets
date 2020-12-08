//
// Created by jimte on 2020-12-04.
//

#ifndef MAIN_CPP_WORLD_H
#define MAIN_CPP_WORLD_H

#include "../game_objects/Game_Object.h"
#include "../game_objects/Textured_Object.h"
#include "../game_objects/Player.h"

#include<SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>

class World
{
public:
    //~World();

    void tick(sf::Time);

    void render(sf::RenderWindow &window);

    bool load_level(std::string const& file_name);

    void add_object(std::shared_ptr<Game_Object> const& game_object);

    std::shared_ptr<Game_Object> get_player_ptr() const;

    bool collides(Game_Object const& a, Game_Object const& b) const;

    std::vector<std::shared_ptr<Game_Object>> collides_with(Game_Object &me) const;

private:
    std::vector<std::shared_ptr<Game_Object>> game_objects;
};


#endif //MAIN_CPP_WORLD_H
