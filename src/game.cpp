#include "game.h"
#include "window.h"

using namespace std;

Game::Game(WindowRunner &window) : window(window), player(nullptr), game_model(nullptr), game_view(nullptr), game_over(false)
{
    this->audio.load(CHUNK1_MSC);
    this->gameover.load(GAMEOVER_SNG);
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

    for(Entity* e : this->entities)
        delete e;
}

void Game::update()
{
    this->game_view->update(); //On update la view que le jeu soit en pause ou non

    if(!this->game_view->isPaused())
    {
        if(!this->game_over)
        {
            if(!this->player->getModel()->isDead())
            {
                for(Chunk* c : this->game_model->getVisibleChunks())
                    for(Obstacle* o : c->getModel()->getObstacles())
                        if(o->checkCollision(*this->player->getModel()))
                            o->action(*this->game_model);

                for( Entity* e : this->entities)
                    if(e->checkCollision(*this->player->getModel()))
                        e->action(*this->player);
            }

            else
            {
                this->player->getView()->getDead_song().play();
                this->audio.stop();
                this->gameover.play();
                this->game_over = !this->player->getView()->getDeadAnim()->playOneTime();
            }

            this->game_model->update();
            this->player->update();

            if(this->player->getModel()->needMoveBackground())
                this->game_model->setFireOffset(this->game_model->getFireOffset() - this->player->getBackgroundShift());

            this->player->getModel()->setDeadLine(this->game_model->getFireOffset());
        }

        else
        {
            window.setState(GAME_OVER);
        }
    }
}

GameView* Game::getView()
{
    return this->game_view;
}

GameModel *Game::getModel()
{
    return this->game_model;
}

void Game::create()
{
    string previous_pseudo = "";

    if(this->game_view != nullptr)
        delete this->game_view;

    if(this->game_model != nullptr)
    {
        previous_pseudo = this->game_model->getPseudo();
        delete this->game_model;
    }

    if(this->player != nullptr)
        delete this->player;

    for(Chunk* c : this->chunks)
        delete c;

    for(Entity* e : this->entities)
        delete e;

    this->chunks.clear();
    this->entities.clear();

    this->player = new Player();
    this->game_model = new GameModel(*this->player, this->chunks, this->entities);

    if(previous_pseudo != "")
        this->game_model->setPseudo(previous_pseudo);

    this->game_view = new GameView(this->window, *this->game_model, *this->player, this->chunks, this->entities);
    this->game_over = false;

    this->audio.play();
}
