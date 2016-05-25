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
    /*!
     * \brief Button permet de créer un bouton graphique avec la SFML
     * \param text Texte affiché sur le bouton
     * \param action Action effectuée par le bouton (voir enum State)
     */
    Button(const std::string &text, const State action, const int pos_x=0, const int pos_y=0, const int width=500, const int height=80);
    ~Button();

    /*!
     * \brief setBoundaries Applique un filtre sur l'image afin de "découper" une certaine zone
     */
    void setBoundaries(const int pos_x, const int pos_y, const int width, const int height);

    /*!
     * \brief setImage Permet de définir une image sur le bouton
     * \param filename Chemin d'accès vers le fichier
     */
    void setImage(const std::string filename);

    /*!
     * \brief processEvent Gère les évenements des boutons
     */
    void processEvent(WindowRunner &window, sf::Event & event);


    void setPosition(int x, int y);
    std::pair<int, int> getPosition() const;

    std::pair<int, int> getSize() const;

    void setText(std::string text);

    std::string toUpper(std::string str) const;
};

#endif // BUTTON_H
