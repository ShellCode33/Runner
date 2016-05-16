#ifndef PLATFORM_MODEL_H
#define PLATFORM_MODEL_H

#include "movable.h"
#include "player.h"
#include "collision.h"

class PlatformModel : public Movable
{
public:
    PlatformModel();
    ~PlatformModel();

    bool checkCollision(Movable &m);
    void action(Player &player);

    bool getPlayer_on_platform() const;

private:
    bool player_on_platform;

};

#endif //PLATFORM_MODEL_H
