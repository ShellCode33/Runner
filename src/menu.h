#ifndef MENU_H
#define MENU_H

#include "button.h"

class WindowRunner;

class Menu
{
private:
  WindowRunner & window;
  sf::Image *menu_bg;
  Button campaign, survival, options, about, leave;

public:
    Menu(WindowRunner & window);
    ~Menu();

    void show();

};

#endif
