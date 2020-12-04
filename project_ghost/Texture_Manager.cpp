//
// Created by jimte on 2020-12-04.
//

#include "Texture_Manager.h"
sf::Texture* Texture_Manager::get_texture(const std::string &name)
{
    std::string file_path{"/home/jimte/TDP005/project_ghost/sprite_data/"};

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
    return new_texture;
}

Texture_Manager Texture_Manager::texture_storage;