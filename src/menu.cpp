#include "menu.h"

using namespace sf;
using namespace std;

Menu::Menu(WindowRunner & window) : window(window)
{
  menu_bg = new Image();
  menu_bg.loadFromFile("../img/menu_bg.png");
}

Menu::~Menu()
{
  delete menu_bg;
}

void Menu::show()
{
  window.draw(menu_bg);
}
