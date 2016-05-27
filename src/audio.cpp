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

void Audio::setLoop()
{
    this->sound.setLoop(true);
}

void Audio::stop()
{
    this->sound.stop();
}

void Audio::pause()
{
    this->sound.pause();
}

void Audio::coin_taken()
{
sf::Music music;
music.openFromFile(COIN_TAKEN_SNG);
music.play();
}
