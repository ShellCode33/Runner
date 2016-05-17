/*!
 * \file missile_model.h
 * \class MissileModel
 * \brief Modèle du missile suiveur
 * \author Clément
 *
 */

#ifndef MISSILE_MODEL
#define MISSILE_MODEL

#include "movable.h"
#include "player.h"
#include "collision.h"

class MissileModel : public Movable
{
public:
    /*!
     * \brief MissileModel
     * \param player passé en paramètre car le missile doit suivre le joueur
     */
    MissileModel(PlayerModel &player);
    ~MissileModel();

    /*!
     * \brief update gère la direction la vitesse et le déplacement du missile
     */
    void update();

    /*!
     * \brief action enlève de la vie au joueur
     * \param player
     */
    void action(Player &player);
    bool checkCollision(Movable &m) const;

    float getAngle() const;

    bool getExploded() const;

private:
    PlayerModel &player;
    float angle; /*!< Angle entre le missile et le joueur */
    bool moving; /*!< état dépend de si le missile est en mouvement ou non */
    bool exploded;

};


#endif
