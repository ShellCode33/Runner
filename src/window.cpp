#include "window.h"

using namespace sf;

WindowRunner::WindowRunner(int width, int height)
{
    this->width = width;
    this->height = height;
}

WindowRunner::~WindowRunner()
{

}

void WindowRunner::create()
{
    window = new RenderWindow(VideoMode(width, height), "Runner");
    for(;;);
}

