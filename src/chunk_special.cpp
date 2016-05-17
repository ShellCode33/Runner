#include "chunk_special.h"

using namespace std;

ChunkSpecial::ChunkSpecial(int pos_x_default, Player &player, std::list<Entity *> &entities) : Chunk(pos_x_default), player(player), entities(entities)
{
    assert(this->texture_base.loadFromFile(BASE_MISSILE_IMG));
    this->base_missile.setTexture(this->texture_base);

    int rand_pos_missile = rand() % (VIEW_HEIGHT - GROUND_DEFAULT*2 - MISSILE_DEFAULT_Y) + MISSILE_DEFAULT_Y;

    this->base_missile.setPosition(this->getModel()->pos_x + (CHUNK_WIDTH - this->base_missile.getLocalBounds().width) / 2, rand_pos_missile);

    this->missile = new MissileSeeker(player);
    this->missile->getModel()->setPosition(make_pair(this->getModel()->pos_x + CHUNK_WIDTH / 2, rand_pos_missile + this->base_missile.getLocalBounds().height / 2));
    entities.push_back(this->missile);
}

ChunkSpecial::~ChunkSpecial()
{
    this->entities.remove(this->missile); //appelle le destructeur de l'entity
    delete this->missile;
}

void ChunkSpecial::update()
{
    Chunk::update();
    MissileModel *missile_model = this->missile->getModel();

    this->base_missile.setPosition(this->getModel()->pos_x + (CHUNK_WIDTH - this->base_missile.getLocalBounds().width) / 2, this->base_missile.getPosition().y);

    if(!missile_model->getExploded())
    {
        this->missile->update();

        if(this->player.getModel()->needMoveBackground())
            missile_model->setPosition(make_pair(missile_model->getX() - this->player.getBackgroundShift(), missile_model->getY()));
    }

    else
        this->entities.remove(this->missile);

    //this->missile->getModel()->setPosition(make_pair(this->getModel()->pos_x + CHUNK_WIDTH / 2, MISSILE_DEFAULT_Y + this->base_missile.getLocalBounds().height / 2)); //Gestion position du missile IMMOBILE
}

void ChunkSpecial::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Chunk::draw(target, states); //On dessine le background des chunks
    target.draw(this->base_missile, states);

    //Le missile est une entity qui sera dessinée après le chunk afin que cette entité soit au dessus de TOUS les chunks et non pas seulement le courant
    //target.draw(*this->missile->getView(), states);
}
