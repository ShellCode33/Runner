#include "chunk_saw.h"

ChunkSaw::ChunkSaw()
{
    this->nb_saw = (rand() % (MAX_SAW_COUNT-1)) + 1;

    int i;
    for(i = 0; i < this->nb_saw; i++)
    {
        this->saw[i] = new Saw();
        this->obstacles.push_back(this->saw[i]);
    }

    int saw_w = this->saw[0]->getLocalBounds().width;
    int saw_h = this->saw[0]->getLocalBounds().height;

    switch(this->nb_saw)
    {
        case 1:
            this->saw[0]->setPositionRelat(CHUNK_WIDTH / 2, CHUNK_HEIGHT - GROUND_DEFAULT);
            break;

        case 2:
            this->saw[0]->setPositionRelat(saw_w / 2, CHUNK_HEIGHT - GROUND_DEFAULT);
            this->saw[1]->setPositionRelat(saw_w * 1.5, CHUNK_HEIGHT - GROUND_DEFAULT);
            break;

        case 3:
            this->saw[0]->setPositionRelat(saw_w / 2, CHUNK_HEIGHT - GROUND_DEFAULT);
            this->saw[1]->setPositionRelat(saw_w * 1.5, CHUNK_HEIGHT - GROUND_DEFAULT);

            if(rand()%2)
                this->saw[2]->setPositionRelat(rand()%2 ? saw_w / 2 : saw_w * 1.5, CHUNK_HEIGHT - GROUND_DEFAULT - 1.8*saw_h);
            else
                this->saw[2]->setPositionRelat(saw_w*2.5, CHUNK_HEIGHT - GROUND_DEFAULT);
            break;

        case 4:
            this->saw[0]->setPositionRelat(saw_w / 2, CHUNK_HEIGHT - GROUND_DEFAULT);
            this->saw[1]->setPositionRelat(saw_w * 1.5, CHUNK_HEIGHT - GROUND_DEFAULT);
            this->saw[2]->setPositionRelat(saw_w / 2, CHUNK_HEIGHT - GROUND_DEFAULT - 2*saw_h);
            this->saw[3]->setPositionRelat(saw_w * 1.5, CHUNK_HEIGHT - GROUND_DEFAULT - 2*saw_h);
            break;
    }
}

ChunkSaw::~ChunkSaw()
{
    //ATTENTION : C'est la classe parente Chunk qui se charge de libérer la mémoire allouée pour les obstacles
}

void ChunkSaw::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Chunk::draw(target, states);

    int i;
    for(i = 0; i < this->nb_saw; i++)
        target.draw(*this->saw[i], states);
}

void ChunkSaw::update()
{
    Chunk::update();

    int i;
    for(i = 0; i < this->nb_saw; i++)
    {
        this->saw[i]->update();
        this->saw[i]->setPosition(this->pos_x + this->saw[i]->getPosition().first, this->saw[i]->getPosition().second);
    }
}
