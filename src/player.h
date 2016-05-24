#ifndef PLAYER_H
#define PLAYER_H

#include "player_model.h"
#include "player_view.h"

class Player
{
public:
    Player();
    ~Player();
    PlayerView* getView();
    PlayerModel* getModel();

    bool needMoveBackground() const;
    void setMoveBackground(bool value);
    int getBackgroundShift() const;

    void update();

    void kill();
    void addEffect(Effect *effect, unsigned long time);

private:
    PlayerModel player_model;
    PlayerView player_view;


};

#endif // PLAYER_H
