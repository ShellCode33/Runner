#include "platform_view.h"

PlatformView::PlatformView(PlatformModel &model) : model(model)
{
    assert(this->texture_platform.loadFromFile("PLATFORM_IMG"));
    this->setTexture(this->texture_platform);
    this->setPosition(this->model.getX(), this->model.getY());
}

PlatformView::~PlatformView()
{

}

void PlatformView::update()
{
    this->setPosition(this->model.getX(), this->model.getY());
}
