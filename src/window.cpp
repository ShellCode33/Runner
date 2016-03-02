#include "window.h"

using namespace sf;
using namespace std;

WindowRunner::WindowRunner()
{
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
    // Create a window with the same pixel depth as the desktop
    VideoMode desktop = VideoMode::getDesktopMode();

    if(desktop.width / desktop.height != 16/9)
    {
        Utils::log(string("Sorry resolution ") + desktop.width + "x" + desktop.height + " isn't supported. Only 16/9 screens.");
        exit(1);
    }

    window = new RenderWindow(desktop, "Runner", Style::Fullscreen);
    state = SPLASH;

    ScreenWait splash_screen("../Runner/img/splash.jpg", "<< Press Space To Play >>");
    splash_screen.setTextPosition(Vector2f((window->getSize().x - splash_screen.getTextWidth()) / 2, (window->getSize().y - splash_screen.getTextHeight()) / 1.2));

    Menu menu(this);

    window->setFramerateLimit(60);

    while(window->isOpen())
    {
        processEvent();
        window->clear();

        switch(state)
        {
            case SPLASH:
                window->draw(splash_screen.getBackground());
                window->draw(splash_screen.getText());
                break;

            case MENU:
                menu.show();
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
