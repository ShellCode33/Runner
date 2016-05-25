#include "chunk_view.h"

using namespace sf;

ChunkView::ChunkView(ChunkModel &model) : model(model)
{
    assert(this->texture_ground.loadFromFile(GROUND_CHUNK_IMG));
    this->sprite_ground.setTexture(this->texture_ground);

    assert(this->texture_background.loadFromFile(BACKGROUND_CHUNK_IMG));
    this->sprite_background.setTexture(this->texture_background);
}

ChunkView::~ChunkView()
{

}

void ChunkView::update()
{
    this->sprite_background.setPosition(model.pos_x, 0);
    this->sprite_ground.setPosition(model.pos_x, VIEW_HEIGHT - GROUND_DEFAULT);
}

void ChunkView::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(this->sprite_ground, states);
    target.draw(this->sprite_background, states);
}
