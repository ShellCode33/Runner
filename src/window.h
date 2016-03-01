#ifndef WINDOW_H
#define WINDOW_H

#include "menu.h"
#include "game.h"
#include <SFML/Graphics.hpp>

enum State
{
    SPLASH,
    MENU,
    GAME
};

class WindowRunner
{
private:
    sf::RenderWindow *window;
    int width;
    int height;
    void processEvent();
    Game *game;
    Config *config;
    State state;


public:
    WindowRunner();
    ~WindowRunner();
    void create();
    void draw(const sf::Drawable &drawable, const sf::RenderStates &states=sf::RenderStates::Default);

};

#endif //WINDOW_H
