//
// Created by jimte on 2020-12-04.
//

#ifndef MAIN_CPP_WORLD_H
#define MAIN_CPP_WORLD_H

#include<SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include <filesystem>
#include <fstream>

#include "../game_objects/Game_Object.h"

class World
{
public:
    World() = delete;
    explicit World(sf::RenderWindow &window);

    void tick(sf::Time);
    void render(sf::RenderWindow &window);

    void add_object(std::shared_ptr<Game_Object> const& game_object);

    //std::shared_ptr<Game_Object> get_player_ptr() const;
    bool collides(Game_Object const& a, Game_Object const& b) const;
    std::vector<std::shared_ptr<Game_Object>> collides_with(Game_Object &me) const;

    sf::RenderWindow& stored_window;


private:
    std::vector<std::shared_ptr<Game_Object>> game_objects;
};


#endif //MAIN_CPP_WORLD_H
