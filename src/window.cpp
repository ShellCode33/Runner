#include "window.h"

using namespace sf;

WindowRunner::WindowRunner()
{
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
    // Create a window with the same pixel depth as the desktop
    VideoMode desktop = VideoMode::getDesktopMode();
    window = new RenderWindow(desktop, "Runner", Style::Fullscreen);
    state = SPLASH;

    Sprite splash;
    Texture splash_texture;
    splash_texture.loadFromFile("../Runner/img/splash.jpg");
    splash.setTexture(splash_texture);

    Menu menu(this);

    window->setFramerateLimit(60);

    while(window->isOpen())
    {
        processEvent();
        window->clear();

        switch(state)
        {
            case SPLASH:
                window->draw(splash);
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
