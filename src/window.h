#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include <unordered_set>
#include "const.h"
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
    Menu menu;
    Config config;
    Game game;
    State state;
    int resolution_x, resolution_y;


public:
    WindowRunner();
    ~WindowRunner();
    void create();
    void draw(const sf::Drawable &drawable, const sf::RenderStates &states=sf::RenderStates::Default);
    State getState() const;
    void setState(const State &value);
};

#endif //WINDOW_H
