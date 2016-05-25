#include "chunk_view.h"

using namespace sf;

ChunkView::ChunkView(ChunkModel &model) : model(model), actual_theme(model.getTheme())
{
    assert(this->texture_ground[0].loadFromFile(GROUND_CHUNK_IMG));
    assert(this->texture_background[0].loadFromFile(BACKGROUND_CHUNK_IMG));
    assert(this->texture_ground[1].loadFromFile(GROUND_CHUNK_IMG2));
    assert(this->texture_background[1].loadFromFile(BACKGROUND_CHUNK_IMG2));

    this->sprite_ground.setTexture(this->texture_ground[this->actual_theme]);
    this->sprite_background.setTexture(this->texture_background[this->actual_theme]);
}

ChunkView::~ChunkView()
{

}

void ChunkView::update()
{
    if(this->actual_theme != this->model.getTheme())
    {
        this->actual_theme = this->model.getTheme();
        this->sprite_background.setTexture(this->texture_background[this->actual_theme]);
        this->sprite_ground.setTexture(this->texture_ground[this->actual_theme]);
    }

    this->sprite_background.setPosition(model.pos_x, 0);
    this->sprite_ground.setPosition(model.pos_x, VIEW_HEIGHT - GROUND_DEFAULT);
}

void ChunkView::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(this->sprite_ground, states);
    target.draw(this->sprite_background, states);

}
