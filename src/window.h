#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include "game.h"
#include "menu.h"

class WindowRunner
{
private:
    sf::RenderWindow *window;
    int width;
    int height;
    void processEvent();
    Game *game;
    Config *config;


public:
    WindowRunner(int width=600, int height=600);
    ~WindowRunner();
    void create();

};

#endif //WINDOW_H
