#include "window.h"

using namespace sf;

WindowRunner::WindowRunner(int width, int height)
{
    this->width = width;
    this->height = height;

    //On créait une config du jeu, qu'on va lui passer en paramètre
    this->config = new Config("config");
    this->game = new Game(this->config, this);
}

WindowRunner::~WindowRunner()
{
    delete this->game;
    delete this->config;
}

void WindowRunner::create()
{
    Menu menu(*this);
    // Create a window with the same pixel depth as the desktop
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window = new RenderWindow(desktop, "Runner", Style::Fullscreen);

    window->setFramerateLimit(60);

    while(window->isOpen())
    {
        processEvent();
        window->clear();
        menu.show();
        //game->run();
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

                    default: break;
                }

                break;

            default: break;
        }
    }
}
