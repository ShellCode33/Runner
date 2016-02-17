#include "window.h"

using namespace sf;

WindowRunner::WindowRunner(int width, int height)
{
    this->width = width;
    this->height = height;
    this->game = new Game(this);
}

WindowRunner::~WindowRunner()
{
    delete this->game;
}

void WindowRunner::create()
{
    window = new RenderWindow(VideoMode(width, height), "Runner");

    while(window->isOpen())
    {
        processEvent();
        window->clear();
        game->run();
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

                break;

            default: break;
        }
    }
}
