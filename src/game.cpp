#include "game.h"
#include "window.h"

Game::Game(WindowRunner &window) : window(window), game_over(false)
{
    srand(time(NULL));
}

Game::~Game()
{
    if(this->game_view != nullptr)
        delete this->game_view;

    if(this->game_model != nullptr)
        delete this->game_model;

    if(this->player != nullptr)
        delete this->player;

    for(Chunk* c : this->chunks)
        delete c;
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
            for(Chunk* c : this->game_model->getVisibleChunks())
                for(Obstacle* o : c->getModel()->getObstacles())
                    if(o->checkCollision(*this->player->getModel()))
                        o->action(*this->player);

            for(Entity* e : this->entities)
                if(e->checkCollision(*this->player->getModel()))
                    e->action(*this->player);
        }

        else
            this->game_over = !this->player->getView()->getDeadAnim()->playOneTime();
    }

    else
    {
        window.setState(GAME_OVER);

        delete this->game_view;
        delete this->game_model;
        delete this->player;

        this->game_view = nullptr;
        this->game_model = nullptr;
        this->player = nullptr;

        for(Chunk* c : this->chunks)
            delete c;

        for(Entity* e : this->entities)
            delete e;
    }
}

GameView* Game::getView()
{
    return this->game_view;
}

void Game::create()
{
    this->chunks.clear();
    this->entities.clear();

    this->player = new Player();
    this->game_model = new GameModel(*this->player, this->chunks, this->entities);
    this->game_view = new GameView(this->window, *this->game_model, *this->player, this->chunks, this->entities);
    this->game_over = false;
}
