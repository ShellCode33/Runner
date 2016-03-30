/*!
 * \class ScreenWait
 * \brief Classe utilisée afin de mettre une image en fond ainsi qu'un texte et attend que la touche espace soit pressée
 * \author Clément
 */

#ifndef SCREENWAIT_H
#define SCREENWAIT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cassert>
#include "const.h"

class WindowRunner;

class ScreenWait : public sf::Drawable
{
private:
    WindowRunner* window;
    sf::Sprite *background;
    sf::Texture *background_texture;
    sf::Text *text;
    sf::Font *font;

public:
    ScreenWait(WindowRunner* window, const std::string filename, const std::string text);
    ~ScreenWait();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /*!
     * \brief Change l'image de fond
     * \param filename : chemin d'accès de l'image
     */
    void setBackground(const std::string filename);

    /*!
     * \brief Change le texte qui sera au dessus de l'image
     * \param value : Texte affiché
     */
    void setText(const std::string value);

    /*!
     * \brief Change la position du texte
     * \param pos : Vecteur de position
     */
    void setTextPosition(const sf::Vector2f pos);
    float getTextWidth() const;
    float getTextHeight() const;

    /*!
     * \brief Gère les évenements qui le concerne
     * \param event : Evenements SFML
     */
    virtual void processEvent(sf::Event &event);
};

#endif //SCREENWAIT_H
