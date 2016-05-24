#include "missile_view.h"

using namespace sf;

MissileView::MissileView(MissileModel &model) : Animation(20.0), model(model), smoke(50.f), anim_updated(false), anim_ended(false)
{
    assert(this->texture_missile.loadFromFile(MISSILE_IMG));
    this->setTexture(this->texture_missile);
    this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
    this->setPosition(this->model.getX(), this->model.getY());

    assert(this->smoke_texture.loadFromFile(DEAD_ANIM));
    this->smoke.setTexture(this->smoke_texture);

    int i, j;
    for(i = 0; i < 5; i++)
        for(j = 0; j < 2; j++)
            this->smoke.addClip(IntRect(256*j, 256*i, 256, 256));

    this->smoke.setOrigin(this->smoke.getLocalBounds().width / 2, this->smoke.getLocalBounds().height / 2);
}

MissileView::~MissileView()
{

}

void MissileView::update()
{
    if(!this->model.getExploded())
    {
        Animation::update();
        this->setRotation(this->model.getAngle());
        this->setPosition(this->model.getX(), this->model.getY());
        this->smoke.setPosition(this->model.getX(), this->model.getY());
    }

    else if(!this->anim_updated)
    {
        this->setTexture(*this->smoke.getTexture());
        this->setSpeed(this->smoke.getSpeed());
        this->setOrigin(this->smoke.getOrigin());
        this->removeClips();

        for(IntRect* r : this->smoke.getClips())
            this->addClip(*r);

        this->anim_updated = true;
    }

    else if(!this->anim_ended)
    {
        this->setPosition(this->model.getX(), this->model.getY());
        this->anim_ended = !Animation::playOneTime();
    }
}

bool MissileView::isDeadAnimFinished()
{
    return this->anim_ended;
}
