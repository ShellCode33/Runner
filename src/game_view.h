#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include "gamestate.h"
#include "chunk.h"
#include "chunk_saw.h"
#include "animation.h"
#include "game_model.h"
#include "player.h"

class WindowRunner;

class GameView : public sf::Drawable
{
public:
    GameView(WindowRunner& window, GameModel& model, Player &player);
    ~GameView();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void processEvent(sf::Event & event);
    void update();
    void setGroundHeight(const int ground_height);
    int getGroundHeight() const;

private:
    WindowRunner& window;
    GameModel &game_model;
    std::list<Chunk*> chunks;

    sf::Texture fire_texture;
    Animation fire, fire2;
    Player &player;

};

#endif //GAMEVIEW_H
