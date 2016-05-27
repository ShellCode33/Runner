#include "heart_view.h"

using namespace sf;

HeartView::HeartView(HeartModel &model) : Animation(50.f), model(model), sound_played(false)
{
    this->sound.load(BONUS_TAKEN_SNG);

    assert(this->heart_texture.loadFromFile(HEART_IMG));
    this->setTexture(this->heart_texture);
}

HeartView::~HeartView()
{

}

void HeartView::update()
{
    if(!this->model.isTaken())
    {
        Animation::update();
        this->setPosition(this->model.getX(), this->model.getY());
    }

    else if(!this->sound_played)
    {
        this->sound.play();
        this->sound_played = true;
    }
}
