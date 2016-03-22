#include "animation.h"

#include <iostream>

using namespace sf;
using namespace std;

Animation::Animation(const long ms) : speed_ms(ms), current_clip_i(0), x_offset(0), y_offset(0), anim_enabled(true)
{
    this->timer = chrono::system_clock::now();
}

Animation::~Animation()
{
    for(IntRect *p_clip : this->clips)
        delete p_clip;
}

Animation::Animation(const Animation &copy) : Sprite(copy), speed_ms(copy.speed_ms)
{
    this->operator=(copy); // Same job here
}

void Animation::update()
{
    if(this->anim_enabled)
    {
        auto diff = chrono::system_clock::now() - this->timer;
        auto msec = chrono::duration_cast<chrono::milliseconds>(diff);

        if(msec.count() > this->speed_ms)
        {
            this->timer = chrono::system_clock::now();
            this->current_clip_i = (this->current_clip_i + 1) % this->clips.size(); //On passe au clip suivant
            IntRect offset_rect = *this->clips[this->current_clip_i];
            offset_rect.top += y_offset;
            offset_rect.left += x_offset;
            this->setTextureRect(offset_rect);
        }
    }
}

Animation& Animation::operator=(const Animation &other)
{
    this->current_clip_i = other.current_clip_i;
    this->timer = chrono::system_clock::now();
    this->setTexture(*other.getTexture());

    int i;
    for(i = 0; i < (int)other.clips.size(); i++)
    {
        IntRect *new_value = new IntRect();
        *new_value = *other.clips[i];
        this->clips.push_back(new_value);
    }

    return *this;
}

void Animation::setOffset(const int x, const int y)
{
    this->x_offset = x;
    this->y_offset = y;
}

void Animation::addClip(const IntRect &clip)
{
    IntRect *p_clip = new IntRect();
    *p_clip = clip;
    this->clips.push_back(p_clip);
    this->setTextureRect(*p_clip); //On définit le dernier clip ajouté comme étant celui par défaut
}

void Animation::setAnimEnabled(bool value)
{
    this->anim_enabled = value;
}
