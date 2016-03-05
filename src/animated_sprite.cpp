#include "animated_sprite.h"

using namespace sf;

AnimatedSprite::AnimatedSprite(const unsigned int speed_ms) : speed_ms(speed_ms), current_clip_i(0)
{
    struct tm default_time;
    default_time.tm_hour = 0;   default_time.tm_min = 0; default_time.tm_sec = 0;
    default_time.tm_year = 100; default_time.tm_mon = 0; default_time.tm_mday = 1;

    this->timer = mktime(&default_time);
}

AnimatedSprite::~AnimatedSprite()
{
    for(IntRect *p_clip : this->clips)
        delete p_clip;
}

void AnimatedSprite::addClip(const IntRect &clip)
{
    IntRect *p_clip = new IntRect();
    *p_clip = clip;
    this->clips.push_back(p_clip);
}

void AnimatedSprite::draw(RenderTarget &target, RenderStates states)
{
    this->setTextureRect(*this->clips[this->current_clip_i]);
    target.draw(*this);

    time_t current_time;
    time(&current_time);

    if(difftime(current_time, this->timer) > this->speed_ms)
    {
        time(&this->timer);
        this->current_clip_i = (this->current_clip_i + 1) % this->clips.size(); //On passe au clip suivant
    }
}
