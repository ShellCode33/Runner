#include "menu.h"
#include "window.h"

using namespace sf;
using namespace std;

Menu::Menu(WindowRunner &window) :  window(window), campaign("CAMPAIGN", CAMPAIGN, 150, 400), survival("SURVIVAL", SURVIVAL, 150, 510), high_score("HIGH SCORES", HIGH_SCORES, 150, 620),
                                    options("OPTIONS", OPTIONS, 150, 730), about("ABOUT", ABOUT, 150, 840), leave("EXIT", EXIT, 150, 950)//position non ajustable, à corriger
{
    assert(this->menubg_texture.loadFromFile(MENU_BG));
    this->menu_bg = new Sprite(this->menubg_texture);
}

Menu::~Menu()
{
    delete this->menu_bg;
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*this->menu_bg, states);
    target.draw(this->campaign, states);
    target.draw(this->survival, states);
    target.draw(this->high_score, states);
    target.draw(this->options, states);
    target.draw(this->about, states);
    target.draw(this->leave, states);
}

void Menu::processEvents(Event & event)
{
    this->campaign.processEvent(this->window, event);
    this->survival.processEvent(this->window, event);
    this->high_score.processEvent(this->window, event);
    this->options.processEvent(this->window, event);
    this->about.processEvent(this->window, event);
    this->leave.processEvent(this->window, event);
}
