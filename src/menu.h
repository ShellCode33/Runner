#ifndef MENU_H
#define MENU_H

#include "const.h"
#include "button.h"

class WindowRunner;

class Menu : public sf::Drawable
{
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Texture *menubg_texture;
    sf::Sprite *menu_bg;
    Button campaign, survival, options, about, leave;

public:
    Menu();
    ~Menu();

};

#endif // MENU_H
