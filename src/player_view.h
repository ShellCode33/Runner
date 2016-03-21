#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "movable.h"
#include "player.h"
#include "animation.h"

class WindowRunner;

class PlayerView : public Animation
{
public:
    PlayerView(const std::string filename_player_img, Player &model);
    ~PlayerView();
    void processEvents(WindowRunner &window, sf::Event &event);
    void update();

private:
    sf::Texture player_texture;
    Player& player;


};

#endif // PLAYERVIEW_H
