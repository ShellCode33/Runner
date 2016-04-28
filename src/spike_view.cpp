#include "spike_view.h"

SpikeView::SpikeView(SpikeModel &model) : model(model)
{
    assert(this->texture.loadFromFile(SPIKE_IMG));
    this->setTexture(this->texture);
}

SpikeView::~SpikeView()
{

}

void SpikeView::update()
{
    this->setPosition(this->model.getX(), this->model.getY());
}
