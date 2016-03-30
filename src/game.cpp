#include "game.h"
#include "window.h"

Game::Game(WindowRunner &window) : window(window), game_over(false)
{
    this->player = new Player();
    this->game_model = new GameModel();
    this->game_view = new GameView(window, *this->game_model, *this->player);
    srand(time(NULL));
}

Game::~Game()
{
    delete this->game_view;
    delete this->game_model;
    delete this->player;
}

void Game::update()
{
    if(!this->game_over)
    {
        this->game_model->update();
        this->game_view->update();
        this->player->update();

        if(this->player->getModel()->needMoveBackground())
            this->game_model->setFireOffset(this->game_model->getFireOffset() - this->player->getBackgroundShift());

        this->player->getModel()->setDeadLine(this->game_model->getFireOffset());


        if(!this->player->getModel()->isDead())
        {
            for(Chunk* c : this->game_view->getVisibleChunks())
                for(Obstacle* o : c->getObstacles())
                    if(o->checkCollision(*player))
                        o->action(*player);
        }

        else
            this->game_over = !this->player->getView()->getDeadAnim()->playOneTime();
    }

    else
    {
        window.setState(GAME_OVER);

        //reset game
        delete this->game_view;
        delete this->game_model;
        delete this->player;

        this->player = new Player();
        this->game_model = new GameModel();
        this->game_view = new GameView(window, *this->game_model, *this->player);
        this->game_over = false;
    }
}

GameView* Game::getView()
{
    return this->game_view;
}
