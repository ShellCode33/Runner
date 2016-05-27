/*!
 * \file about_tab.h
 * \class AboutTab
 * \brief Onglet à propos dans le menu
 * \author Clément
 */

#ifndef ABOUT_TAB_H
#define ABOUT_TAB_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <string>
#include "animation.h"
#include "const.h"

class WindowRunner;

class AboutTab : public sf::Drawable
{
public:
    /*!
     * \brief AboutTab constructeur
     */
    AboutTab();
    ~AboutTab();

    /*!
     * \brief draw est une fonction virtuelle qui permet de dessiner AboutTab
     * \param target
     * \param states
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /*!
     * \brief update permet de mettre a jour AboutTab ainsi que ses animations
     */
    void update();

    /*!
     * \brief processEvent gère les conséquences suivant l'evenement
     * \param window
     * \param event
     */
    void processEvent(WindowRunner & window, sf::Event & event);


private:
    sf::Texture *snoop_texture, *snoop_texture_reverse;
    Animation first_snoop, second_snoop;

    sf::Texture illu_texture;
    sf::Sprite illuminati;

    sf::Font font;
    sf::Text text[4]; /*!< Obligé d'en faire un tableau car la SFML ne gère pas le text-align center */

};

#endif // ABOUT_TAB_H
