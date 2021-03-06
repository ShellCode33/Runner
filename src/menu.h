/*!
 * \file menu.h
 * \brief Menu qui sera affiché et avec lequel l'utilisateur pourra interagir
 * \author J3ry, ShellCode
 */

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
    Button survival, high_score, options, about, leave;

public:
    Menu(WindowRunner &window);
    ~Menu();

    /*!
     * \brief Gère les évenements qui le concerne
     * \param event : Evenements SFML
     */
    void processEvents(sf::Event & event);
    void update();
};

#endif // MENU_H
