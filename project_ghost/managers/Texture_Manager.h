//
// Created by jimte on 2020-12-04.
//

#ifndef MAIN_CPP_TEXTURE_MANAGER_H
#define MAIN_CPP_TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>

/**
 * \brief Loads and keeps track of textures.
 * To save computing power and avoid errors related to creating a lot of texture objects
 * this manager will load all requested textures ONCE and then keep them in the memory.
 */
class Texture_Manager
{
public:
    static sf::Texture *get_texture(std::string const &name); /**<Used to load textures anywhere in the program*/

private:
    Texture_Manager() = default;

    static Texture_Manager texture_storage;

    std::map<std::string, std::unique_ptr<sf::Texture>> textures;

};

/**
 * \brief Loads and keeps track of fonts.
 * To save computing power and avoid errors related to creating a lot of font objects
 * this manager will load all requested fonts ONCE and then keep them in the memory.
 */
class Font_Manager
{
public:
    static sf::Font& get_font(std::string const& name); /**<Used to load fonts anywhere in the program*/

private:
    Font_Manager() = default;

    static Font_Manager font_storage;

    std::map<std::string, std::unique_ptr<sf::Font>> fonts;
};


#endif //MAIN_CPP_TEXTURE_MANAGER_H
