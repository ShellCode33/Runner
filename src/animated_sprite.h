#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <time.h>

class AnimatedSprite : public sf::Sprite
{
public:
    AnimatedSprite(const unsigned int speed=0);
    ~AnimatedSprite();
    void addClip(const sf::IntRect& clip);
    void draw(sf::RenderTarget& target, sf::RenderStates states);

private:
    std::vector<sf::IntRect*> clips; //Contient les differentes zones de la texture qui formeront les animations du sprite
    const unsigned int speed_ms; //temps entre 2 sprites (en millisecondes)
    unsigned int current_clip_i;
    time_t timer;


};

#endif // ANIMATEDSPRITE_H
