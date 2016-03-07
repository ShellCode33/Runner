#include "window.h"
#include "const.h"

using namespace sf;
using namespace std;

WindowRunner::WindowRunner() : menu(*this), game_view(*this), splash_screen(this, SPLASH_IMG, SPLASH_TEXT)
{
    //On définit une view qui s'ajustera automatiquement à toutes les tailles d'écran
    this->reset(FloatRect(0, 0, 1920, 1080));
}

WindowRunner::~WindowRunner()
{

}

void WindowRunner::create()
{
    // Récupère la résolution du bureau
    desktop = VideoMode::getDesktopMode();

    window = new RenderWindow(desktop, TITLE_WINDOW, Style::Fullscreen);
    this->setViewport(FloatRect(0.f, 0.f, 1.f, 1.f));
    window->setView(*this);
    state = SPLASH;

    splash_screen.setTextPosition(Vector2f((this->getSize().x - splash_screen.getTextWidth()) / 2, (this->getSize().y - splash_screen.getTextHeight()) / 1.2));

    window->setFramerateLimit(FRAMERATE);

    while(window->isOpen())
    {
        processEvent();
        window->clear();

        switch(state)
        {
            case SPLASH:
                window->draw(splash_screen);
                break;

            case MENU:
                window->draw(menu);
                break;

            case SURVIVAL:
            case CAMPAIGN:
                window->draw(game_view);
                break;

            case OPTIONS:

                break;

            case ABOUT:

                break;

            case EXIT:
                window->close();
                break;
        }

        window->display();
    }
}


void WindowRunner::processEvent()
{
    Event event;

    while(window->pollEvent(event))
    {
        //Dispatch events processing
        menu.processEvents(event);
        splash_screen.processEvent(event);
        game_view.processEvent(event);
    }
}

State WindowRunner::getState() const
{
    return state;
}

void WindowRunner::setState(const State &value)
{
    state = value;
}

void WindowRunner::draw(const Drawable &drawable, const RenderStates &states)
{
    window->draw(drawable, states);
}

RenderWindow & WindowRunner::getRender() const
{
  return *window;
}
