#include "magnet_view.h"

MagnetView::MagnetView(MagnetModel &model) : model(model)
{
    assert(this->texture.loadFromFile(MAGNET_IMG));
    this->setTexture(this->texture);
}

void MagnetView::update()
{
    if(!this->model.isTaken())
    {
        this->setPosition(this->model.getX(), this->model.getY());
    }
}
