#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <chrono>

class Animation : public sf::Sprite
{
private:
    sf::Texture texture;
    std::vector<sf::IntRect*> clips; //Contient les differentes zones de la texture qui formeront les animations du sprite
    const double speed_ms; //temps entre 2 sprites (en millisecondes)
    unsigned int current_clip_i;
    clock_t timer;

public:
    Animation(const double speed_ms=3.d);
    ~Animation();
    void addClip(const sf::IntRect& clip);
    void update();
};

#endif // ANIMATION_H
