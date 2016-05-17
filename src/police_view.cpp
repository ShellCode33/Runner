#include "police_view.h"

using namespace std;
using namespace sf;

PoliceView::PoliceView(PoliceModel &model) : model(model)
{
    assert(this->car_texture.loadFromFile(POLICE_CAR_IMG));
    this->car.setTexture(this->car_texture);

    assert(this->wheel_texture.loadFromFile(WHEEL_CAR_IMG));
    this->wheels[0].setTexture(this->wheel_texture);
    this->wheels[1].setTexture(this->wheel_texture);
    this->wheels[0].setOrigin(this->wheels[0].getLocalBounds().width / 2, this->wheels[0].getLocalBounds().height / 2);
    this->wheels[1].setOrigin(this->wheels[1].getLocalBounds().width / 2, this->wheels[1].getLocalBounds().height / 2);
}

PoliceView::~PoliceView()
{


}

void PoliceView::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(this->car, states);
    target.draw(this->wheels[0], states);
    target.draw(this->wheels[1], states);
}

void PoliceView::update()
{
    pair<int, int> pos = this->model.getPosition();
    this->car.setPosition(pos.first, pos.second);
    this->wheels[0].setPosition(pos.first + 67, pos.second + 76); //+67 et +76 sont les distances entre la voiture et les roues
    this->wheels[1].setPosition(pos.first + 284, pos.second + 76);//+284 et +76 sont les distances entre la voiture et les roues
    this->wheels[0].rotate(-POLICE_SPEED);
    this->wheels[1].rotate(-POLICE_SPEED);
}
