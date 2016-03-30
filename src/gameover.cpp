#include "gameover.h"

using namespace std;

GameOver::GameOver(WindowRunner *window) : ScreenWait(window, GAME_OVER_BG, ""), window(window), button_menu("Menu", MENU), button_playagain("Play Again", SURVIVAL)
{
    assert(this->board_texture.loadFromFile(GAME_OVER_BOARD));
    this->board.setTexture(this->board_texture);
    this->board.setPosition((VIEW_WIDTH - this->board.getLocalBounds().width) / 2, VIEW_HEIGHT);


    this->timer = chrono::system_clock::now();
}

GameOver::~GameOver()
{

}

void GameOver::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    ScreenWait::draw(target, states);
    target.draw(this->board);
}

void GameOver::update()
{
    if(this->board.getPosition().y > (VIEW_HEIGHT - this->board.getLocalBounds().height) / 2)
    {
        auto diff = chrono::system_clock::now() - this->timer;
        auto msec = chrono::duration_cast<chrono::milliseconds>(diff);

        if(msec.count() > 20)
        {
            this->board.setPosition(this->board.getPosition().x, this->board.getPosition().y - 10);
            this->timer = chrono::system_clock::now();
        }
    }
}

void GameOver::processEvent(sf::Event &event)
{
    ScreenWait::processEvent(event);
}
