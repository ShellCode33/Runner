#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "const.h"
#include "movable.h"
#include "animation.h"
#include "player_model.h"

class WindowRunner;

class PlayerView : public Animation
{
public:
    PlayerView(PlayerModel &model);
    ~PlayerView();
    void processEvents(WindowRunner &window, sf::Event &event);
    void update();

private:
    sf::Texture player_texture;
    PlayerModel& player_model;


};

#endif // PLAYERVIEW_H
