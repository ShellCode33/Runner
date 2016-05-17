#ifndef POLICE_MODEL_H
#define POLICE_MODEL_H

#include "movable.h"
#include "collision.h"

class PoliceModel : public Movable
{
public:
    PoliceModel();
    ~PoliceModel();
    void update();
    bool checkCollision(Movable &m) const;

    bool getCollision() const;
    void setCollision(bool value);

private:
    bool collision;

};

#endif
