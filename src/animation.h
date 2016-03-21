#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <chrono>

class Animation : public sf::Sprite
{
private:
    std::vector<sf::IntRect*> clips; //Contient les differentes zones de la texture qui formeront les animations du sprite
    const double speed_ms; //temps entre 2 sprites (en millisecondes)
    unsigned int current_clip_i;
    clock_t timer;
    int x_offset, y_offset;
    bool anim_enabled;


public:
    Animation(const double speed_ms=250.0);
    Animation(const Animation &copy);
    ~Animation();
    void addClip(const sf::IntRect& clip);
    void update();
    Animation& operator=(const Animation &other);
    void setOffset(const int x, const int y);

    void setAnimEnabled(bool value);
};

#endif // ANIMATION_H
