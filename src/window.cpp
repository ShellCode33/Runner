#include "window.h"

using namespace sf;

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
    window = new RenderWindow(desktop, "Runner", Style::Fullscreen);
    state = SPLASH;

    Sprite splash;
    Texture splash_texture;
    assert(splash_texture.loadFromFile("../Runner/img/splash.jpg"));
    splash.setTexture(splash_texture);

    Font splash_font;
    assert(splash_font.loadFromFile("../Runner/fonts/onthemove.ttf"));

    Text text_splash;
    text_splash.setFont(splash_font);
    text_splash.setCharacterSize(100);
    text_splash.setColor(Color::Black);
    text_splash.setString("<< Press Space To Play >>");
    text_splash.setPosition(Vector2f((window->getSize().x - text_splash.getLocalBounds().width) / 2, (window->getSize().y - text_splash.getLocalBounds().height) / 1.2));

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
                window->draw(text_splash);
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
