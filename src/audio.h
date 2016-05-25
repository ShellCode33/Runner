#ifndef AUDIO_H
#define AUDIO_H

#include <SFML/Audio.hpp>
#include <cassert>
#include <string>

class Audio
{
public:
    void load(std::string filename);
    void play();
    void setPlayingOffset(sf::Time timeOffset);

private:
    sf::Sound sound;
    sf::SoundBuffer buffer;

};

#endif //AUDIO_H
