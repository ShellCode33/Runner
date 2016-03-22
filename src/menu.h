#ifndef MENU_H
#define MENU_H

#include "const.h"
#include "button.h"

class WindowRunner;

class Menu : public sf::Drawable
{
private:
    WindowRunner &window;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Texture menubg_texture;
    sf::Sprite *menu_bg;
    Button campaign, survival, options, about, leave;

public:
    Menu(WindowRunner &window);
    ~Menu();
    void processEvents(sf::Event & event);

};

#endif // MENU_H
