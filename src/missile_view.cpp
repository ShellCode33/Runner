#include "missile_view.h"

MissileView::MissileView(MissileModel &model) : Animation(20.0), model(model)
{
    assert(this->texture_missile.loadFromFile(MISSILE_IMG));
    this->setTexture(this->texture_missile);
    this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
    this->setPosition(this->model.getX(), this->model.getY());
}

MissileView::~MissileView()
{

}

void MissileView::update()
{
    Animation::update();
    this->setRotation(this->model.getAngle());
    this->setPosition(this->model.getX(), this->model.getY());
}
