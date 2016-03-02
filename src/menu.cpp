#include "menu.h"
#include "window.h"

using namespace sf;
using namespace std;

Menu::Menu(WindowRunner *window) :  campaign("Campaign", 100, 400, 280, 50), survival("Survival", 100, 470, 280, 50),
                                    options("Options", 100, 540, 280, 50), about("About", 100, 610, 280, 50), leave("Exit", 100, 680, 280, 50)
{
    this->window = window;

    this->menubg_texture = new Texture();
    this->menubg_texture->loadFromFile(MENU_BG);
    this->menu_bg = new Sprite(*this->menubg_texture);
}

Menu::~Menu()
{
    delete this->menubg_texture;
    delete this->menu_bg;
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    this->window->draw(*this->menu_bg, states);
    this->window->draw(campaign, states);
    this->window->draw(survival, states);
    this->window->draw(options, states);
    this->window->draw(about, states);
    this->window->draw(leave, states);
}
