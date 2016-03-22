#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include "player_view.h"
#include "gamestate.h"
#include "chunk.h"
#include "animation.h"

class WindowRunner;
class Game;

class GameView : public sf::Drawable
{
public:
    GameView(WindowRunner& window, Game& model);
    ~GameView();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void processEvent(sf::Event & event);
    void update();
    void setGroundHeight(const int ground_height);
    int getGroundHeight() const;

private:
    WindowRunner& window;
    Game &game;
    PlayerView player_view;
    std::list<Chunk*> chunks;

    sf::Texture fire_texture;
    Animation fire, fire2;

};

#endif //GAMEVIEW_H
