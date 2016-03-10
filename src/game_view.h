#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include "game.h"
#include "player_view.h"
#include "gamestate.h"

class WindowRunner;

class GameView : public sf::Drawable
{
public:
    GameView(WindowRunner& window);
    ~GameView();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void processEvent(sf::Event & event);
    void update();
    void setGroundHeight(const int ground_height);
    int getGroundHeight() const;

private:
    WindowRunner& window;
    PlayerView player_view;
    Game game; //model
    unsigned int groundHeight;

};

#endif //GAMEVIEW_H
