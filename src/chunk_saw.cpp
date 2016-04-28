#include "chunk_saw.h"

using namespace std;

ChunkSaw::ChunkSaw(int pos_x_default) : Chunk(pos_x_default)
{
    this->nb_saw = rand() % MAX_SAW_COUNT + 1;

    int i;
    for(i = 0; i < this->nb_saw; i++)
    {
        this->saw[i] = new Saw(0, 0, 130, 131);
        this->addObstacle(this->saw[i]->getModel());
    }

    int saw_w = this->saw[0]->getModel()->getWidth();
    int saw_h = this->saw[0]->getModel()->getHeight();

    switch(this->nb_saw)
    {
        case 1:
            this->saw[0]->getModel()->setPositionRelat(CHUNK_WIDTH / 2, CHUNK_HEIGHT - GROUND_DEFAULT);
            break;

        case 2:
            this->saw[0]->getModel()->setPositionRelat(saw_w / 2, CHUNK_HEIGHT - GROUND_DEFAULT);
            this->saw[1]->getModel()->setPositionRelat(saw_w * 1.5, CHUNK_HEIGHT - GROUND_DEFAULT);
            break;

        case 3:
            this->saw[0]->getModel()->setPositionRelat(saw_w / 2, CHUNK_HEIGHT - GROUND_DEFAULT);
            this->saw[1]->getModel()->setPositionRelat(saw_w * 1.5, CHUNK_HEIGHT - GROUND_DEFAULT);
            this->saw[2]->getModel()->setPositionRelat(rand()%2 ? saw_w / 2 : saw_w * 1.5, CHUNK_HEIGHT - GROUND_DEFAULT - 1.8*saw_h);

            break;

        case 4:
            this->saw[0]->getModel()->setPositionRelat(saw_w / 2, CHUNK_HEIGHT - GROUND_DEFAULT);
            this->saw[1]->getModel()->setPositionRelat(saw_w * 1.5, CHUNK_HEIGHT - GROUND_DEFAULT);
            this->saw[2]->getModel()->setPositionRelat(saw_w / 2, CHUNK_HEIGHT - GROUND_DEFAULT - 2*saw_h);
            this->saw[3]->getModel()->setPositionRelat(saw_w * 1.5, CHUNK_HEIGHT - GROUND_DEFAULT - 2*saw_h);
            break;
    }
}

ChunkSaw::~ChunkSaw()
{

}

void ChunkSaw::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Chunk::draw(target, states);

    int i;
    for(i = 0; i < this->nb_saw; i++)
        target.draw(*this->saw[i]->getView(), states);
}

void ChunkSaw::update()
{
    Chunk::update();

    int i;
    for(i = 0; i < this->nb_saw; i++)
    {
        this->saw[i]->getModel()->setPosition(make_pair(this->getModel()->pos_x + this->saw[i]->getModel()->getRelatPosition().first, this->saw[i]->getModel()->getRelatPosition().second));
        this->saw[i]->update();
    }
}
