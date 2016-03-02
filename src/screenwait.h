#ifndef SCREENWAIT_H
#define SCREENWAIT_H

#include <iostream>
#include <SFML/Graphics.hpp>

class ScreenWait
{
private:
    sf::Sprite *background;
    sf::Texture *background_texture;
    sf::Text *text;

public:
    ScreenWait();
    ~ScreenWait();
    void setBackground(std::string filename);
};

#endif //SCREENWAIT_H
