#include "game.h"
#include "window.h"

Game::Game(WindowRunner &window) : window(window), game_over(false)
{
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
                    if(o->checkCollision(*this->player->getModel()))
                        o->action(*this->player);
        }

        else
            this->game_over = !this->player->getView()->getDeadAnim()->playOneTime();
    }

    else
    {
        window.setState(GAME_OVER);

        Utils::log("delete game");
        delete this->game_view;
        delete this->game_model;
        delete this->player;

        //this->create();
    }
}

GameView* Game::getView()
{
    return this->game_view;
}

void Game::create()
{
    this->player = new Player();
    this->game_model = new GameModel();
    this->game_view = new GameView(window, *this->game_model, *this->player);
    this->game_over = false;
}
