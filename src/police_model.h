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
    bool collision; /*!< Permet de déterminer si la collision a déjà eu lieu de manière à ne pas la compter plusieurs fois */

};

#endif
