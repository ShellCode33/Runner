#include "animation.h"

#include <iostream>

using namespace sf;
using namespace std;

Animation::Animation(const unsigned long ms) : speed_ms(ms), timer(speed_ms), x_offset(0), y_offset(0), anim_enabled(true), current_clip_i(0)
{
    timer.begin();
}

Animation::~Animation()
{
    removeClips();
}

Animation::Animation(const Animation &copy) : Sprite(copy), speed_ms(copy.speed_ms), timer(speed_ms)
{
    this->operator=(copy); // Same job here
}

void Animation::update()
{
    if(this->anim_enabled && this->clips.size() > 0)
    {
        if(this->timer.isFinish())
        {
            this->timer.reset();
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
    for(IntRect* r : this->clips)
        delete r;

    this->clips.clear();

    this->current_clip_i = other.current_clip_i;
    this->timer.reset();
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

bool Animation::operator==(const Animation &second)
{
    bool equals = true;

    if(this->clips.size() != second.clips.size())
        equals = false;

    else
    {
        int i;
        for(i = 0; equals && i < (int)this->clips.size(); i++)
            if(this->clips.at(i) != second.clips.at(i))
                equals = false;
    }

    return equals;
}

bool Animation::operator!=(const Animation &second)
{
    return !this->operator ==(second);
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

void Animation::removeClips()
{
    for(IntRect *p_clip : this->clips)
        delete p_clip;

    this->clips.clear();
}

bool Animation::playOneTime()
{
    if(this->current_clip_i >= this->clips.size())
        return false;

    if(this->timer.isFinish())
    {
        this->timer.reset();
        this->setTextureRect(*this->clips[this->current_clip_i]);
        this->current_clip_i = (this->current_clip_i + 1); //On passe au clip suivant
    }

    return true;
}

void Animation::setSpeed(unsigned long value)
{
    this->speed_ms = value;
    this->timer.changeTimer(value);
}

unsigned long Animation::getSpeed() const
{
    return this->speed_ms;
}

std::vector<IntRect *> Animation::getClips() const
{
    return this->clips;
}
