//
// Created by jimte on 2020-12-14.
//

#include "Sound_Manager.h"

sf::SoundBuffer* Sound_Manager::get_sound(const std::string &name)
{
    std::string file_path{"../audio_data/"};

    // Check if the sound is loaded and return if it is.
    auto loaded = soundbuffer_storage.sound_buffers.find(name);
    if(loaded != soundbuffer_storage.sound_buffers.end())
    {
        return loaded->second.get();
    }

    // Try to load the sound and add it to the soundbuffer_storage
    sf::SoundBuffer* new_sound{new sf::SoundBuffer()};
    if(!new_sound->loadFromFile(file_path + name))
    {
        throw std::logic_error("Failed to load sound: " + name);
    }

    soundbuffer_storage.sound_buffers.insert(std::make_pair(name, std::unique_ptr<sf::SoundBuffer>(new_sound)));
    return soundbuffer_storage.sound_buffers.find(name)->second.get();
}

void Sound_Manager::play_sound(const std::string &name)
{
    // If the sound is already loaded just play it.
    auto loaded = sound_storage.sounds.find(name);
    if(loaded != sound_storage.sounds.end())
    {
        loaded->second.get()->play();
    }

    // Try to load the sound and add it to the sound_storage
    sf::Sound* new_sound{new sf::Sound()};
    new_sound->setBuffer(*get_sound(name));

    sound_storage.sounds.insert(std::make_pair(name, std::unique_ptr<sf::Sound>(new_sound)));
    sound_storage.sounds.find(name)->second.get()->play();
}

Sound_Manager Sound_Manager::soundbuffer_storage;
Sound_Manager Sound_Manager::sound_storage;