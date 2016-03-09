#include "menu.h"
#include "window.h"

using namespace sf;
using namespace std;

Menu::Menu(WindowRunner &window) :  window(window), campaign("Campaign", CAMPAIGN, 150, 450, 500, 91), survival("Survival", SURVIVAL, 150, 560, 500, 91),
                                    options("Options", OPTIONS, 150, 670, 500, 91), about("About", ABOUT, 150, 780, 500, 91), leave("Exit", EXIT, 150, 890, 500, 91)
{
    this->menubg_texture.loadFromFile(MENU_BG);
    this->menu_bg = new Sprite(this->menubg_texture);
}

Menu::~Menu()
{
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
    campaign.processEvent(window, event);
    survival.processEvent(window, event);
    options.processEvent(window, event);
    about.processEvent(window, event);
    leave.processEvent(window, event);
}
