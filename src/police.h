#ifndef POLICE_H
#define POLICE_H

#include "police_model.h"
#include "police_view.h"
#include "entity.h"

class Police : public Entity
{
public:
    Police();
    ~Police();
    void update();

    PoliceModel *getModel();
    PoliceView *getView();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void action(Player &player);
    bool checkCollision(Movable &m) const;


private:
    PoliceView view;
    PoliceModel model;

};

#endif
