//
// Created by jimte on 2020-12-14.
//

#ifndef MAIN_CPP_SOUND_MANAGER_H
#define MAIN_CPP_SOUND_MANAGER_H

#include <SFML/Audio.hpp>
#include <map>

class Sound_Manager
{
public:
    static sf::SoundBuffer* get_sound(std::string const& name);

    static void play_sound(std::string const& name);

private:
    Sound_Manager() = default;

    static Sound_Manager soundbuffer_storage;
    static Sound_Manager sound_storage;

    std::map<std::string, std::unique_ptr<sf::SoundBuffer>> sound_buffers;
    std::map<std::string, std::unique_ptr<sf::Sound>> sounds;

};


#endif //MAIN_CPP_SOUND_MANAGER_H
