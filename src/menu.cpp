#include "menu.h"
#include "window.h"

using namespace sf;
using namespace std;

Menu::Menu(WindowRunner *window) :  campaign("Campaign", 100, 400, 280, 50), survival("Survival", 100, 470, 280, 50),
                                    options("Options", 100, 540, 280, 50), about("About", 100, 610, 280, 50), leave("Exit", 0, 680, 280, 50)
{
    this->window = window;

    menubg_texture = new Texture();
    menubg_texture->loadFromFile("../Runner/img/menu_bg.png");
    menu_bg = new Sprite(*menubg_texture);
}

Menu::~Menu()
{
    delete menu_bg;
}

void Menu::show()
{
    window->draw(*menu_bg);
}
