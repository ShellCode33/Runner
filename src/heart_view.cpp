#include "heart_view.h"

using namespace sf;

HeartView::HeartView(HeartModel &model) : Animation(50.f), model(model)
{
    assert(this->heart_texture.loadFromFile(HEART_IMG));
    this->setTexture(this->heart_texture);
}

HeartView::~HeartView()
{

}

void HeartView::update()
{
    Animation::update();

    this->setPosition(this->model.getX(), this->model.getY());
}
