#ifndef AUDIO_H
#define AUDIO_H

#include <SFML/Audio.hpp>
#include <cassert>
#include <string>
#include "const.h"

class Audio
{
public:
    void load(std::string filename);
    void play();
    void setPlayingOffset(sf::Time timeOffset);
    void setLoop();
    void stop();
    void pause();
    static void coin_taken();

private:
    sf::Sound sound;
    sf::SoundBuffer buffer;

};

#endif //AUDIO_H
