#include "menu.h"
#include "window.h"

using namespace sf;
using namespace std;

Menu::Menu(WindowRunner *window) :  campaign("Campaign", 200, 600, 280, 50), survival("Survival", 200, 670, 280, 50),
                                    options("Options", 200, 740, 280, 50), about("About", 200, 810, 280, 50), leave("Exit", 200, 880, 280, 50)
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
    target.draw(*this->menu_bg, states);
    target.draw(campaign, states);
    target.draw(survival, states);
    target.draw(options, states);
    target.draw(about, states);
    target.draw(leave, states);
}

void Menu::processEvents(Event & event)
{
    campaign.processEvent(*window, event);
    survival.processEvent(*window, event);
    options.processEvent(*window, event);
    about.processEvent(*window, event);
    leave.processEvent(*window, event);
}
