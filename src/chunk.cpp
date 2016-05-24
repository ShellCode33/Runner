#include "chunk.h"

using namespace sf;
using namespace std;

Chunk::Chunk(int pos_x_default, Player &player) : model(pos_x_default), view(model), bonus_heart(nullptr), bonus_moon(nullptr), bonus_magnet(nullptr), player(player)
{

}

Chunk::~Chunk()
{
    delete this->bonus_heart;
    delete this->bonus_moon;
    delete this->bonus_magnet;

    for(Coin *c : this->coins)
        delete c;

    for(Platform *p : this->platforms)
        delete p;
}

void Chunk::spawnBonusRandom()
{
    int prob = rand() % 100;

    switch(prob)
    {
        //5% prob d'apparition
        case 0:
        case 10:
        case 20:
        case 30:
        case 40:
            this->bonus_heart = new Heart(CHUNK_WIDTH / 2, CHUNK_HEIGHT - CHUNK_HEIGHT / 4, 91, 80);
            this->addObstacle(this->bonus_heart->getModel());
            break;

        //5% prob d'apparition
        case 1:
        case 11:
        case 21:
        case 31:
        case 41:
            this->bonus_moon = new Moon(*this->player.getModel(), CHUNK_WIDTH / 2, CHUNK_HEIGHT - CHUNK_HEIGHT / 4, 60, 60);
            this->addObstacle(this->bonus_moon->getModel());
            break;

        //5%
        case 2:
        case 12:
        case 22:
        case 32:
        case 42:
            this->bonus_magnet = new Magnet(*this->player.getModel(), CHUNK_WIDTH / 2, CHUNK_HEIGHT - CHUNK_HEIGHT / 4, 55, 62);
            this->addObstacle(this->bonus_magnet->getModel());
            break;


        default: break;
    }
}

void Chunk::update()
{
    this->view.update();

    if(this->bonus_heart != nullptr)
    {
        if(this->bonus_heart->getModel()->isTaken())
        {
            this->removeObstacle(this->bonus_heart->getModel());
            delete this->bonus_heart;
            this->bonus_heart = nullptr;
        }

        else
        {
            this->bonus_heart->getModel()->setPosition(make_pair(this->getModel()->pos_x + this->bonus_heart->getModel()->getRelatPosition().first, this->bonus_heart->getModel()->getRelatPosition().second));
            this->bonus_heart->update();
        }
    }

    if(this->bonus_moon != nullptr)
    {
        if(this->bonus_moon->getModel()->isTaken())
        {
            this->removeObstacle(this->bonus_moon->getModel());
            player.addEffect(this->bonus_moon, 10000.f);

            //On ne le delete pas car c'est un Effect mais on le met quand meme à nullptr
            this->bonus_moon = nullptr;
        }
        else
        {
            this->bonus_moon->getModel()->setPosition(make_pair(this->getModel()->pos_x + this->bonus_moon->getModel()->getRelatPosition().first, this->bonus_moon->getModel()->getRelatPosition().second));
            this->bonus_moon->update();
        }
    }

    if(this->bonus_magnet != nullptr)
    {
        if(this->bonus_magnet->getModel()->isTaken())
        {
            this->removeObstacle(this->bonus_magnet->getModel());
            player.addEffect(this->bonus_magnet, 10000.f);

            //On ne le delete pas car c'est un Effect mais on le met quand meme à nullptr
            this->bonus_magnet = nullptr;
        }

        else
        {
            this->bonus_magnet->getModel()->setPosition(make_pair(this->getModel()->pos_x + this->bonus_magnet->getModel()->getRelatPosition().first, this->bonus_magnet->getModel()->getRelatPosition().second));
            this->bonus_magnet->update();
        }
    }

    list<Coin*> to_remove;

    for(Coin *c : this->coins)
    {
        if(!c->getModel()->isTaken())
        {
            //On décalle en fonction du chunk
            c->getModel()->setPosition((make_pair(this->getModel()->pos_x + c->getModel()->getRelatPosition().first, c->getModel()->getRelatPosition().second)));

            pair<float, float> player_pos = this->player.getModel()->getPosition();

            if(this->model.isInChunk(*this->player.getModel()) && this->player.getModel()->getAttractCoins()) //Les pièces sont attirées par le joueur
            {
                for(Coin *c : this->coins)
                {
                    pair<float, float> direction(player_pos.first + this->player.getModel()->getWidth() / 2 - c->getModel()->getX(), player_pos.second + this->player.getModel()->getHeight() / 2 - c->getModel()->getY());

                    int angle = atan2(direction.second, direction.first) * 180 / 3.14159;

                    if(angle < 0)
                        angle += 360;

                    int x_speed, y_speed; //Le déplacement selon x et y doit se faire en fonction de l'angle

                    /* On sépare en 4 cas différents :
                     * - Lorsque le joueur est en haut à gauche de la piece
                     * - Lorsque le joueur est en bas à gauche de la piece
                     * - Lorsque le joueur est en bas à droite de la piece
                     * - Lorsque le joueur est en haut à droite de la piece
                     */

                    if(angle > 270 && angle <= 360)
                    {
                        x_speed = (angle - 270) * COIN_SPEED_MAGNET / 90;
                        y_speed = x_speed - COIN_SPEED_MAGNET;
                    }

                    else if(angle > 180 && angle <= 270)
                    {
                        y_speed = -(angle - 180) * COIN_SPEED_MAGNET / 90;
                        x_speed = -(y_speed + COIN_SPEED_MAGNET);
                    }

                    else if(angle > 90 && angle <= 180)
                    {
                        x_speed = -(angle - 90) * COIN_SPEED_MAGNET / 90;
                        y_speed = (COIN_SPEED_MAGNET + x_speed);
                    }

                    else
                    {
                        y_speed = angle * COIN_SPEED_MAGNET / 90;
                        x_speed = COIN_SPEED_MAGNET - y_speed;
                    }

                    assert(abs(x_speed) + abs(y_speed) <= COIN_SPEED_MAGNET);

                    c->getModel()->setPositionRelat(c->getModel()->getRelatPosition().first + x_speed, c->getModel()->getRelatPosition().second + y_speed);
                }
            }

            c->update();
        }

        else
            to_remove.push_back(c);
    }

    for(Coin *c : to_remove)
    {
        this->removeObstacle(c->getModel());
        this->coins.remove(c);
        delete c;
    }
}

ChunkModel* Chunk::getModel()
{
    return &this->model;
}

ChunkView* Chunk::getView()
{
    return &this->view;
}

void Chunk::addObstacle(Obstacle *obstacle)
{
    this->model.addObstacle(obstacle);
}

void Chunk::removeObstacle(Obstacle *obstacle)
{
    this->model.removeObstacle(obstacle);
}

void Chunk::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->view, states);

    if(this->bonus_heart != nullptr)
        target.draw(*this->bonus_heart->getView(), states);

    if(this->bonus_moon != nullptr)
        target.draw(*this->bonus_moon->getView(), states);

    if(this->bonus_magnet != nullptr)
        target.draw(*this->bonus_magnet->getView(), states);

    for(Coin *c : this->coins)
        target.draw(*c->getView(), states);
}
