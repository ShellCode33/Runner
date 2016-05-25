#include "audio.h"


void Audio::load(std::string filename)
{
    assert(this->buffer.loadFromFile(filename));
    this->sound.setBuffer(this->buffer);
}

void Audio::play()
{
    this->sound.play();
}

void Audio::setPlayingOffset(sf::Time timeOffset)
{
    this->sound.setPlayingOffset(timeOffset);
}
