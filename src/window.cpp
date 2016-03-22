#include "window.h"
#include "const.h"

using namespace sf;
using namespace std;

WindowRunner::WindowRunner() : window(NULL), menu(*this), game_view(*this, game), splash_screen(this, SPLASH_IMG, SPLASH_TEXT)
{
    //On définit une view qui s'ajustera automatiquement à toutes les tailles d'écran
    this->reset(FloatRect(0, 0, VIEW_WIDTH, VIEW_HEIGHT));
}

WindowRunner::~WindowRunner()
{
    if(this->window != NULL)
        delete this->window;
}

void WindowRunner::create()
{
    // Récupère la résolution du bureau
    this->desktop = VideoMode::getDesktopMode();

    this->window = new RenderWindow(this->desktop, TITLE_WINDOW, Style::Close);
    this->setViewport(FloatRect(0.f, 0.f, 1.f, 1.f));
    this->window->setView(*this);
    this->state = SPLASH;

    this->splash_screen.setTextPosition(Vector2f((this->getSize().x - this->splash_screen.getTextWidth()) / 2, (this->getSize().y - this->splash_screen.getTextHeight()) / 1.2));

    this->window->setFramerateLimit(FRAMERATE);
    this->window->setVerticalSyncEnabled(false);

    while(this->window->isOpen())
    {
        processEvent();
        this->window->clear();

        switch(this->state)
        {
            case SPLASH:
                this->window->draw(this->splash_screen);
                break;

            case MENU:
                this->window->draw(this->menu);
                break;

            case SURVIVAL:
            case CAMPAIGN:
                this->game.update();
                this->game_view.update();
                this->window->draw(this->game_view);
                break;

            case OPTIONS:
                this->window->draw(this->option_tab);
                break;

            case ABOUT:
                this->about_tab.update();
                this->window->draw(this->about_tab);
                break;

            case EXIT:
                this->window->close();
                break;
        }

        this->window->display();
    }
}


void WindowRunner::processEvent()
{
    Event event;

    while(this->window->pollEvent(event))
    {
        switch(this->state)
        {
            case SPLASH:
                this->splash_screen.processEvent(event);
                break;

            case MENU:
                this->menu.processEvents(event);
                break;

            case SURVIVAL:
                this->game_view.processEvent(event);
                break;
            case CAMPAIGN:
                this->game_view.processEvent(event);
                break;

            case OPTIONS:

                break;

            case ABOUT:
                this->about_tab.processEvent(*this, event);
                break;

        default: break;
        }

        //Permet de revenir au MENU avec escape quoi qu'il arrive, mais devra être enlevé à l'avenir (juste pratique le temps de développer)
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            this->state = MENU;
    }
}

State WindowRunner::getState() const
{
    return this->state;
}

void WindowRunner::setState(const State &value)
{
    this->state = value;
}

void WindowRunner::draw(const Drawable &drawable, const RenderStates &states)
{
    this->window->draw(drawable, states);
}

RenderWindow & WindowRunner::getRender() const
{
  return *this->window;
}
