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

void Animation::addClip(const IntRect &clip)
{
    IntRect *p_clip = new IntRect();
    *p_clip = clip;
    this->clips.push_back(p_clip);
}
