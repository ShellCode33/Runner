/*!
 * \file animation.h
 * \class Animation
 * \brief Classe permettant de faire un sprite animé de plusieurs séquences
 * \author ShellCode
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "timer.h"

class Animation : public sf::Sprite
{
private:
    unsigned long speed_ms; /*!< temps entre 2 sprites (en millisecondes) */
    Timer timer; /*!< Timer utilisé pour gérer le temps entre 2 zones de la texture */
    int x_offset, y_offset; /*!< Utilisé pour pouvoir créer un décalage des rectangles de lecture (ex: passer d'une ligne de sprites à une autre) */
    bool anim_enabled;  /*!< Permet de faire des pauses ou d'arrêter l'animation d'un sprite */


public:
    /*!
     * \brief Animation
     * \param ms temps entre 2 images
     */
    Animation(const unsigned long ms);
    Animation(const Animation &copy);
    ~Animation();

    /*!
     * \brief addClip permet d'ajouter un rectangle de lecture bien précis à l'animation
     * \param clip rectangle de lecture en question
     */
    void addClip(const sf::IntRect& clip);

    /*!
     * \brief Se charge de mettre à jour le sprite, doit être appelé à chaque tour de boucle
     */
    void update();

    /*!
     * \brief setOffset permet de définir un espace entre les rectangles de lecture
     */
    void setOffset(const int x, const int y);

    /*!
     * \brief setAnimEnabled permet de desactiver l'animation (temporairement ou pas)
     */
    void setAnimEnabled(bool value);

    /*!
     * \brief removeClips supprime tous les éléments qui composent l'animation
     */
    void removeClips();

    /*!
     * \brief playOneTime se charge de lire l'animation qu'une seule fois
     * \return false si l'animation est terminée et true si l'animation est en cours
     */
    bool playOneTime();

    Animation& operator=(const Animation &other);
    bool operator==(const Animation &second);
    bool operator!=(const Animation &second);


    /*!
     * \brief setSpeed permet de changer la vitesse entre 2 animations
     * \param value
     */
    void setSpeed(unsigned long value);
    unsigned long getSpeed() const;

    /*!
     * \brief getClips
     * \return un vecteur contenant un pointeur vers l'ensemble des clips
     */
    std::vector<sf::IntRect*> getClips() const;

protected:
    std::vector<sf::IntRect*> clips; /*!< Contient les differentes zones de la texture qui formeront les animations du sprite */
    unsigned int current_clip_i; /*!< Zone courante de la texture */
};

#endif // ANIMATION_H
