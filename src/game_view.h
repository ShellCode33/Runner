#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include "game.h"

class WindowRunner;

class GameView : public sf::Drawable
{
public:
    GameView(WindowRunner& window);
    ~GameView();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Game game; //model

};

#endif //GAMEVIEW_H
