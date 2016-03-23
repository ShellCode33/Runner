/*!
 * \file animation.h
 * \brief Classe permettant de faire un sprite animé de plusieurs séquences
 * \author Clément
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <chrono>

class Animation : public sf::Sprite
{
private:
    std::vector<sf::IntRect*> clips; /*!< Contient les differentes zones de la texture qui formeront les animations du sprite */
    const long speed_ms; /*!< temps entre 2 sprites (en millisecondes) */
    unsigned int current_clip_i; /*!< Zone courante de la texture */
    std::chrono::high_resolution_clock::time_point timer; /*!< Timer utilisé pour gérer le temps entre 2 zones de la texture */
    int x_offset, y_offset; /*!< Utilisé pour pouvoir créer un décalage des rectangles de lecture (ex: passer d'une ligne de sprites à une autre) */
    bool anim_enabled;  /*!< Permet de faire des pauses ou d'arrêter l'animation d'un sprite */


public:
    Animation(const long ms);
    Animation(const Animation &copy);
    ~Animation();
    void addClip(const sf::IntRect& clip);
    void update();
    Animation& operator=(const Animation &other);
    void setOffset(const int x, const int y);

    void setAnimEnabled(bool value);
};

#endif // ANIMATION_H
