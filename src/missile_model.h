#ifndef MISSILE_MODEL
#define MISSILE_MODEL

#include "movable.h"
#include "player.h"
#include "collision.h"

class MissileModel : public Movable
{
public:
    MissileModel(Player &player);
    ~MissileModel();
    void update();
    void action(Player &player);
    bool checkCollision(Movable &m);

    float getAngle() const;

private:
    Player &player;
    float angle;
    std::pair<int, int> velocity;
    bool moving;

};


#endif
