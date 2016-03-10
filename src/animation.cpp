#include "animation.h"

#include <iostream>

using namespace sf;

Animation::Animation(const double speed_ms) : speed_ms(speed_ms), current_clip_i(0)
{
    this->timer = clock();
}

Animation::~Animation()
{
    for(IntRect *p_clip : this->clips)
        delete p_clip;
}

void Animation::update()
{
    this->setTextureRect(*this->clips[this->current_clip_i]);

    clock_t current = clock();
    double ms = (double)(current - this->timer ) / CLOCKS_PER_SEC * 1000;

    if(ms > this->speed_ms)
    {
        this->timer = clock();
        this->current_clip_i = (this->current_clip_i + 1) % this->clips.size(); //On passe au clip suivant
    }
}

Animation &Animation::operator=(const Animation &other)
{
    this->current_clip_i = other.current_clip_i;
    this->timer = clock();
    this->setTexture(*other.getTexture());

    int i;
    for(i = 0; i < other.clips.size(); i++)
    {
        IntRect *new_value = new IntRect();
        *new_value = *other.clips[i];
        this->clips.push_back(new_value);
    }

    return *this;
}

void Animation::addClip(const IntRect &clip)
{
    IntRect *p_clip = new IntRect();
    *p_clip = clip;
    this->clips.push_back(p_clip);
}
