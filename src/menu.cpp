#include "menu.h"

using namespace sf;
using namespace std;

Menu::Menu(WindowRunner *window) : campaign(""), survival(""), options(""), about(""), leave("")
{
    this->window = window;

    Texture menubg_texture;
    menubg_texture.loadFromFile("../Runner/img/menu_bg.png");
    menu_bg = new Sprite(menubg_texture);
}

Menu::~Menu()
{
    delete menu_bg;
}

void Menu::show()
{
    window->draw(menu_bg);
}
