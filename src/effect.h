#ifndef EFFECT_H
#define EFFECT_H

class PlayerModel;

class Effect
{
public:
    Effect(PlayerModel &player) : player(player) {  }
    virtual void start(PlayerModel& player) = 0;
    virtual void stop(PlayerModel& player) = 0;

private:
    PlayerModel &player;
};

#endif // EFFECT_H
