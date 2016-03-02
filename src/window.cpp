#include "window.h"

using namespace sf;
using namespace std;

WindowRunner::WindowRunner()
{
    //On définit une view qui s'ajustera automatiquement à toutes les tailles d'écran
    this->reset(FloatRect(0, 0, 1920, 1080));

    //On créait une config du jeu, qu'on va lui passer en paramètre
    this->config = new Config("config");
    this->config->readConfig();
    this->game = new Game(this->config, this);
}

WindowRunner::~WindowRunner()
{
    delete this->game;
    delete this->config;
}

void WindowRunner::create()
{
    // Récupère la résolution du bureau
    desktop = VideoMode::getDesktopMode();

    window = new RenderWindow(desktop, "Runner", Style::Fullscreen);
    this->setViewport(FloatRect(0.f, 0.f, 1.f, 1.f));
    window->setView(*this);
    state = SPLASH;

    ScreenWait splash_screen(this, SPLASH_IMG, "<< Press Space To Play >>");
    splash_screen.setTextPosition(Vector2f((this->getSize().x - splash_screen.getTextWidth()) / 2, (this->getSize().y - splash_screen.getTextHeight()) / 1.2));

    Menu menu(this);

    window->setFramerateLimit(60);

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

            case GAME:
                game->run();
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
        switch(event.type)
        {
            case Event::Closed:
                window->close();
                break;

            case Event::KeyPressed:

                switch(event.key.code)
                {
                    case Keyboard::Escape:
                        window->close();
                        break;

                    case Keyboard::Space:

                        if(state == SPLASH)
                            state = MENU;

                        break;

                    default: break;
                }

                break;

            default: break;
        }
    }
}

void WindowRunner::draw(const Drawable &drawable, const RenderStates &states)
{
    window->draw(drawable, states);
}
