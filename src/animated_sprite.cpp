#include "animated_sprite.h"

using namespace sf;

AnimatedSprite::AnimatedSprite(const unsigned int speed) : speed(speed)
{

}

AnimatedSprite::~AnimatedSprite()
{
    for(Sprite *p_sprite : sprites)
        delete p_sprite;
}

void AnimatedSprite::addSprite(Sprite &sprite)
{
    Sprite *p_sprite = new Sprite();
    *p_sprite = sprite;
    sprites.push_back(p_sprite);
}
