//
// Created by jimte on 2020-12-04.
//

#ifndef MAIN_CPP_WORLD_H
#define MAIN_CPP_WORLD_H

#include "../game_objects/Game_Object.h"
#include "../game_objects/Textured_Object.h"
#include "../game_objects/Player.h"
#include "../containers/Player_Info.h"

#include<SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include <filesystem>
#include <fstream>


class World
{
public:
    World() = delete;
    World(sf::RenderWindow &window);

    void tick(sf::Time);
    void render(sf::RenderWindow &window);

    void add_object(std::shared_ptr<Game_Object> const& game_object);

    std::shared_ptr<Game_Object> get_player_ptr() const;
    bool collides(Game_Object const& a, Game_Object const& b) const;
    std::vector<std::shared_ptr<Game_Object>> collides_with(Game_Object &me) const;

    sf::RenderWindow& stored_window;

    void load_level(Player_Info &);

private:
    std::vector<std::shared_ptr<Game_Object>> game_objects;
};


#endif //MAIN_CPP_WORLD_H
