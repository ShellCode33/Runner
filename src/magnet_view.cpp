#include "magnet_view.h"

MagnetView::MagnetView(MagnetModel &model) : model(model), sound_played(false)
{
    this->sound.load(BONUS_TAKEN_SNG);
    assert(this->texture.loadFromFile(MAGNET_IMG));
    this->setTexture(this->texture);
}

void MagnetView::update()
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
