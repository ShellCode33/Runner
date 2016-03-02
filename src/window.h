#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "menu.h"
#include "game.h"
#include "screenwait.h"
#include "utils.h"

enum State
{
    SPLASH,
    MENU,
    GAME
};

class WindowRunner : sf::View
{
private:
    sf::RenderWindow *window;
    sf::VideoMode desktop;
    int width;
    int height;
    void processEvent();
    Game *game;
    Config *config;
    State state;
    int resolution_x, resolution_y;


public:
    WindowRunner();
    ~WindowRunner();
    void create();
    void draw(const sf::Drawable &drawable, const sf::RenderStates &states=sf::RenderStates::Default);

    std::pair<int, int> getResolution();
};

#endif //WINDOW_H
