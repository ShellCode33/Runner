/*!
 * \file button.h
 * \class Button
 * \author Clément
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Mouse.hpp>
#include "const.h"
#include "gamestate.h"
#include <cassert>

class WindowRunner;

class Button : public sf::Drawable
{
private :
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Texture texture; /*!< Texture du bouton */
    sf::Texture texture_hover; /*!< texture utilisée lorsque la souris passe sur le bouton */
    sf::Sprite *sprite;
    sf::Text text; /*!< Texte du bouton */
    sf::Font font; /*!< Police du bouton */
    const State action; /*!< Action que va effectuer le bouton (ex: MENU, GAME_OVER etc...) */

    int pos_x, pos_y; /*!< Position x et y du bouton */
    int width, height; /*!< Largeur et hauteur du bouton */

public :
    Button(const std::string &text, const State action, const int pos_x=0, const int pos_y=0, const int width=500, const int height=80);
    ~Button();
    void setBoundaries(const int pos_x, const int pos_y, const int width, const int height); /*!< Applique un filtre sur l'image afin de "découper" une certaine zone */
    void setImage(const std::string filename); /*!< Permet de définir une image sur le bouton */
    void processEvent(WindowRunner &window, sf::Event & event); /*!< Gère les évenements du bouton */
};

#endif // BUTTON_H
