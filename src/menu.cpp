#include "menu.h"
#include "window.h"

using namespace sf;
using namespace std;

Menu::Menu(WindowRunner &window) :  window(window), survival("SURVIVAL", SURVIVAL, 150, 450), high_score("HIGH SCORES", HIGH_SCORES, 150, 560),
                                    options("OPTIONS", OPTIONS, 150, 670), about("ABOUT", ABOUT, 150, 780), leave("EXIT", EXIT, 150, 890)
{
    assert(this->menubg_texture.loadFromFile(MENU_BACKGROUND_IMG));
    this->menu_bg = new Sprite(this->menubg_texture);
}

Menu::~Menu()
{
    delete this->menu_bg;
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*this->menu_bg, states);
    target.draw(this->survival, states);
    target.draw(this->high_score, states);
    target.draw(this->options, states);
    target.draw(this->about, states);
    target.draw(this->leave, states);
}

void Menu::processEvents(Event & event)
{
    this->survival.processEvent(this->window, event);
    this->high_score.processEvent(this->window, event);
    this->options.processEvent(this->window, event);
    this->about.processEvent(this->window, event);
    this->leave.processEvent(this->window, event);
}

void Menu::update()
{
    this->survival.setText(Utils::translate(WindowRunner::getSetting("lang"), "survival.button"));
    this->high_score.setText(Utils::translate(WindowRunner::getSetting("lang"), "score.button"));
    this->options.setText(Utils::translate(WindowRunner::getSetting("lang"), "options.button"));
    this->about.setText(Utils::translate(WindowRunner::getSetting("lang"), "about.button"));
    this->leave.setText(Utils::translate(WindowRunner::getSetting("lang"), "exit.button"));
}
