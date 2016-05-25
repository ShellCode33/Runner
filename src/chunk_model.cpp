#include "chunk_model.h"

#include "moon_model.h"

Timer ChunkModel::change_background_timer(30000.f, true);
unsigned short ChunkModel::num_theme = 0;

ChunkModel::ChunkModel(int pos_x_default) : pos_x(pos_x_default)
{

}

ChunkModel::~ChunkModel()
{
    /*
     * //Les obstacles ne doivent pas être supprimés car ils sont contenus dans les chunks et ne sont pas alloués dynamiquement
    for(Obstacle* o : this->obstacles)
        delete o;
        */
}

std::list<Obstacle *> ChunkModel::getObstacles() const
{
    return this->obstacles;
}

void ChunkModel::addObstacle(Obstacle *obstacle)
{
    this->obstacles.push_back(obstacle);
}

void ChunkModel::removeObstacle(Obstacle *obstacle)
{
    this->obstacles.remove(obstacle);
}

bool ChunkModel::isInChunk(Movable &m) const
{
    return m.getX() + m.getWidth() > pos_x && m.getX() < pos_x + CHUNK_WIDTH;
}

unsigned int ChunkModel::getTheme() const
{
    return this->num_theme;
}

void ChunkModel::update()
{
    if(this->change_background_timer.isFinish())
    {
        this->change_background_timer.reset();
        this->num_theme = (this->num_theme + 1) % NB_THEMES;
    }
}
