#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button
{
private :
    sf::Sprite *sprite;
    int pos_x, pos_y;
    int width, height;

public :
    Button(std::string filename, int pos_x=0, int pos_y=0, int width=150, int height=150);
    ~Button();

};

#endif
