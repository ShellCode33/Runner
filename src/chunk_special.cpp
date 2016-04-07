#include "chunk_special.h"

using namespace std;

ChunkSpecial::ChunkSpecial(Player &player)
{
    this->missile = new MissileSeeker(player);
    this->missile->Movable::setPosition(make_pair(this->getModel()->pos_x + CHUNK_WIDTH / 2, 100));
    this->missile->setPosition(this->getModel()->pos_x + CHUNK_WIDTH / 2, 100);
}

ChunkSpecial::~ChunkSpecial()
{

}

void ChunkSpecial::update()
{
    Chunk::update();
    this->missile->update();
    this->missile->setPosition(this->getModel()->pos_x + this->missile->getPosition().first, this->missile->getPosition().second);
}

void ChunkSpecial::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    this->draw(target, states); //On dessine le background des chunks
    target.draw(missile->getBaseDraw(), states);
    target.draw(missile->getMissileDraw(), states);
}
