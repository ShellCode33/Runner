#include "moon_view.h"

MoonView::MoonView(MoonModel &model) : model(model)
{
    assert(this->moon_texture.loadFromFile(MOON_IMG));
    this->setTexture(this->moon_texture);
}

MoonView::~MoonView()
{

}

void MoonView::update()
{
    if(!this->model.isTaken())
    {
        this->setPosition(this->model.getX(), this->model.getY());
    }
}
