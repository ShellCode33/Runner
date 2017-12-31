/*!
 * \file player.h
 * \class Player
 * \brief classe regroupant le modèle et la vue du player
 * \author J3ry
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "player_model.h"
#include "player_view.h"

class Player
{
public:
    Player();
    ~Player();
    PlayerView* getView();
    PlayerModel* getModel();

    bool needMoveBackground() const; /*!< Détermine s'il faut déplacement les chunks ou pas */
    void setMoveBackground(bool value); /*!< Permet de signaler que le déplacement des chunks a bien été effectué */
    int getBackgroundShift() const; /*!< Retourne le nombre de pixel dont s'est déplacé le joueur au delà de la limite afin de déplacer les chunks en conséquence */

    void update();

    void kill(); /*!< Tue le joueur */

    /*!
     * \brief addEffect ajoute comme son nom l'indique un effet sur le joueur tel que le moon jump ou l'aimant
     * \param effect
     * \param time correspont au temps en ms que l'effet va durer
     */
    void addEffect(Effect *effect, unsigned long time);

private:
    PlayerModel player_model;
    PlayerView player_view;


};

#endif // PLAYER_H
