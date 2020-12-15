//
// Created by jimte on 2020-12-04.
//

#include "Texture_Manager.h"

sf::Texture* Texture_Manager::get_texture(const std::string &name)
{
    std::string file_path{"../sprite_data/"};

    // Check if the texture is loaded and return if it is.
    auto loaded = texture_storage.textures.find(name);
    if(loaded != texture_storage.textures.end())
    {
        return loaded->second.get();
    }

    // Try to load the texture and add it to the texture_storage
    sf::Texture* new_texture{new sf::Texture()};
    if(!new_texture->loadFromFile(file_path + name))
    {
        throw std::logic_error("Failed to load texture: " + name);
    }

    texture_storage.textures.insert(std::make_pair(name, std::unique_ptr<sf::Texture>(new_texture)));
    return texture_storage.textures.find(name)->second.get();
}

Texture_Manager Texture_Manager::texture_storage;


// Font_Manager
sf::Font &Font_Manager::get_font(const std::string &name)
{
    std::string file_path{"../font_data/"};

    // Check if the font is loaded and return if it is.
    auto loaded = font_storage.fonts.find(name);
    if(loaded != font_storage.fonts.end())
    {
        return *loaded->second.get();
    }

    // Try to load the font and add it to the font_storage
    sf::Font* new_font{new sf::Font()};
    if(!new_font->loadFromFile(file_path + name))
    {
        throw std::logic_error("Failed to load font: " + name);
    }

    font_storage.fonts.insert(std::make_pair(name, std::unique_ptr<sf::Font>(new_font)));
    return *font_storage.fonts.find(name)->second.get();
}

Font_Manager Font_Manager::font_storage;