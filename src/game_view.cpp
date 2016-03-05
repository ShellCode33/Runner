#include "game_view.h"
#include "window.h"

using namespace sf;

GameView::GameView(WindowRunner &window) : window(window), player_view(PLAYER_IMG)
{
}

GameView::~GameView()
{

}

void GameView::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(player_view);
}

void GameView::processEvent(Event &event)
{
    if(this->window.getState() == SURVIVAL)
    {
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            this->window.setState(MENU);
    }
}
