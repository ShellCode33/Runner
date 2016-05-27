#include "moon_view.h"

MoonView::MoonView(MoonModel &model) : model(model), sound_played(false)
{
    this->sound.load(BONUS_TAKEN_SNG);
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

    else if(!this->sound_played)
    {
        this->sound.play();
        this->sound_played = true;
    }
}
