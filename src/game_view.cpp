#include "game_view.h"
#include "window.h"

using namespace sf;

GameView::GameView(WindowRunner &window, Game &model) : window(window), game(model), player_view(PLAYER_IMG, game.player)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        chunks.push_back(*new Chunk(i));
    }
}

GameView::~GameView()
{

}

void GameView::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(player_view, states);

    for(const Chunk& c : chunks)
        target.draw(c);
}

void GameView::processEvent(Event &event)
{
    if(this->window.getState() == SURVIVAL || this->window.getState() == CAMPAIGN)
    {
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            this->window.setState(MENU);

        player_view.processEvents(window, event);
    }
}

void GameView::update()
{
    this->player_view.update();

    for(Chunk& c : chunks)
        c.update();
}
