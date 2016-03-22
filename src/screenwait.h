#ifndef SCREENWAIT_H
#define SCREENWAIT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cassert>
#include "const.h"

class WindowRunner;

class ScreenWait : public sf::Drawable
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    WindowRunner* window;
    sf::Sprite *background;
    sf::Texture *background_texture;
    sf::Text *text;
    sf::Font *font;

public:
    ScreenWait(WindowRunner* window, const std::string filename, const std::string text);
    ~ScreenWait();
    void setBackground(const std::string filename);
    void setText(const std::string value);
    void setTextPosition(const sf::Vector2f pos);
    float getTextWidth() const;
    float getTextHeight() const;
    void processEvent(sf::Event &event);
};

#endif //SCREENWAIT_H
