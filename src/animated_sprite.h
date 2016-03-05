#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "movable.h"

class AnimatedSprite : public Movable
{
public:
    AnimatedSprite(const unsigned int speed=0);
    ~AnimatedSprite();
    void addSprite(sf::Sprite &sprite);

private:
    std::vector<sf::Sprite*> sprites;
    const unsigned int speed; //temps entre 2 sprites

};

#endif // ANIMATEDSPRITE_H
