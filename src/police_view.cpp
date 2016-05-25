#include "police_view.h"

using namespace std;
using namespace sf;

PoliceView::PoliceView(PoliceModel &model) : model(model), circle1(50), circle2(50), circle1_visible(false), circle2_visible(false), timer1(80.f), timer2(50.f)
{
    assert(this->car_texture.loadFromFile(POLICE_CAR_IMG));
    this->car.setTexture(this->car_texture);

    assert(this->wheel_texture.loadFromFile(WHEEL_IMG));
    this->wheels[0].setTexture(this->wheel_texture);
    this->wheels[1].setTexture(this->wheel_texture);
    this->wheels[0].setOrigin(this->wheels[0].getLocalBounds().width / 2, this->wheels[0].getLocalBounds().height / 2);
    this->wheels[1].setOrigin(this->wheels[1].getLocalBounds().width / 2, this->wheels[1].getLocalBounds().height / 2);

    this->circle1.setOrigin(50, 50);
    this->circle2.setOrigin(50, 50);

    this->circle1.setFillColor(Color(255, 0, 0, 100));
    this->circle2.setFillColor(Color(0, 0, 255, 100));

    this->timer1.begin();
    this->timer2.begin();
}

PoliceView::~PoliceView()
{


}

void PoliceView::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(this->car, states);
    target.draw(this->wheels[0], states);
    target.draw(this->wheels[1], states);

    if(this->circle1_visible)
        target.draw(this->circle1);

    if(this->circle2_visible)
        target.draw(this->circle2);
}

void PoliceView::update()
{
    pair<int, int> pos = this->model.getPosition();
    this->car.setPosition(pos.first, pos.second);
    this->wheels[0].setPosition(pos.first + 67, pos.second + 76); //+67 et +76 sont les distances entre la voiture et les roues
    this->wheels[1].setPosition(pos.first + 284, pos.second + 76);//+284 et +76 sont les distances entre la voiture et les roues
    this->wheels[0].rotate(-POLICE_SPEED);
    this->wheels[1].rotate(-POLICE_SPEED);

    this->circle1.setPosition(pos.first + this->model.getWidth() / 2 - 20, pos.second);
    this->circle2.setPosition(pos.first + this->model.getWidth() / 2 + 20, pos.second);

    if(this->timer1.isFinish())
    {
        this->circle1_visible = !this->circle1_visible;
        this->timer1.reset();
    }

    if(this->timer2.isFinish())
    {
        this->circle2_visible = !this->circle2_visible;
        this->timer2.reset();
    }
}
