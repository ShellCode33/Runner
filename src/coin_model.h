/*!
 * \file coin_model.h
 * \class CoinModel
 * \brief Partie modèle des pièces
 * \author Jérémie
 */

#ifndef COIN_MODEL_H
#define COIN_MODEL_H

#include "obstacle.h"

class CoinModel : public Obstacle
{
public:
    /*!
     * \brief CoinModel construceur
     * \param relat_x
     * \param relat_y
     * \param width
     * \param height
     */
    CoinModel(int relat_x, int relat_y, int width, int height);
    ~CoinModel();

    /*!
     * \brief action qui s'applique lorsque le playerModel entre en collision avec la pièce
     * \param game
     */
    void action(GameModel &game);

    /*!
     * \brief update
     */
    void update();

    /*!
     * \brief checkCollision
     * \param m
     * \return true ou false suivant si la collision a lieu ou pas
     */
    bool checkCollision(Movable &m) const;

    bool isTaken() const;

private:
    bool taken; /*!< Attribut utilisé pour déterminer si la pièce a été récupérée par le joueur */
};

#endif // COIN_MODEL_H
