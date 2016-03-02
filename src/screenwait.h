#ifndef SCREENWAIT_H
#define SCREENWAIT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cassert>

class WindowRunner;

class ScreenWait
{
private:
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
    sf::Sprite & getBackground() const;
    sf::Text & getText() const;
};

#endif //SCREENWAIT_H
