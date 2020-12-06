//
// Created by jimte on 2020-12-04.
//

#ifndef MAIN_CPP_TEXTURE_MANAGER_H
#define MAIN_CPP_TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>

class Texture_Manager
{
public:
    static sf::Texture* get_texture(std::string const& name);

private:
    Texture_Manager() = default;

    static Texture_Manager texture_storage;

   std::map<std::string, std::unique_ptr<sf::Texture>> textures;

};


#endif //MAIN_CPP_TEXTURE_MANAGER_H