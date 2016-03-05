#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "movable.h"
#include "player.h"
#include "animated_sprite.h"

class PlayerView : public AnimatedSprite
{
public:
    PlayerView(std::string filename_player_img);
    ~PlayerView();

private:
    sf::Texture player_texture;
    Player player; //Player model


};

#endif // PLAYERVIEW_H
