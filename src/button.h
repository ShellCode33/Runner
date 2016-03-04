#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Mouse.hpp>
#include "const.h"

class WindowRunner;

class Button : public sf::Drawable
{
private :
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Texture *texture;
    sf::Texture *texture_hover; //texture utilisée lorsque la souris passe sur le bouton
    sf::Sprite *sprite;
    sf::Text *text;
    sf::Font *font;

    int pos_x, pos_y;
    int width, height;

public :
    Button(const std::string &text, const int pos_x=0, const int pos_y=0, const int width=280, const int height=50);
    ~Button();
    void setBoundaries(const int pos_x, const int pos_y, const int width, const int height);
    void setImage(const std::string filename);
    void processEvent(WindowRunner &window, sf::Event & event);
};

#endif // BUTTON_H
