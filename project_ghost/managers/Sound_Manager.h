//
// Created by jimte on 2020-12-14.
//

#ifndef MAIN_CPP_SOUND_MANAGER_H
#define MAIN_CPP_SOUND_MANAGER_H

#include <SFML/Audio.hpp>
#include <map>

/**
 * \brief Loads sounds into soundbuffers and saves them to be played when needed.
 * Also saves sound objects for each sound so that it is always played to the end and not cutoff.
 */
class Sound_Manager
{
public:
    static sf::SoundBuffer* get_sound(std::string const& name); /**<If you wish to create your own sound object use this to load the sound-file into a buffer.*/

    static void play_sound(std::string const& name); /**<If you only want a sound-file to play to completion using default settings use this.*/

private:
    Sound_Manager() = default;

    static Sound_Manager soundbuffer_storage;
    static Sound_Manager sound_storage;

    std::map<std::string, std::unique_ptr<sf::SoundBuffer>> sound_buffers;
    std::map<std::string, std::unique_ptr<sf::Sound>> sounds;

};


#endif //MAIN_CPP_SOUND_MANAGER_H
