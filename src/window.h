#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "const.h"
#include "menu.h"
#include "screenwait.h"
#include "utils.h"
#include "gamestate.h"
#include "about_tab.h"
#include "option_tab.h"
#include "game.h"

class WindowRunner : sf::View
{
private:
    sf::RenderWindow *window;
    sf::VideoMode desktop;
    int width;
    int height;
    void processEvent();
    Menu menu;
    ScreenWait splash_screen;
    Game game;

    State state;
    AboutTab about_tab;
    OptionTab option_tab;


public:
    WindowRunner();
    ~WindowRunner();
    void create();
    void draw(const sf::Drawable &drawable, const sf::RenderStates &states=sf::RenderStates::Default) const;
    State getState() const;
    void setState(const State &value);
    sf::RenderWindow & getRender() const;
};

#endif //WINDOW_H
