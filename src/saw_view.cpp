#include "saw_view.h"

using namespace sf;
using namespace std;

SawView::SawView(SawModel &model) : model(model)
{
    assert(this->texture.loadFromFile(SAW_IMG));
    this->setTexture(this->texture);
    this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
}

SawView::~SawView()
{

}

void SawView::update()
{
    this->setPosition(this->model.getPosition().first, this->model.getPosition().second);
    this->rotate(4);
}
