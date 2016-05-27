/*!
 * \file effect.h
 * \class Effect
 * \brief classe abstraite qui permet de gérer la durée d'action des bonus
 * \author Clément
 */

#ifndef EFFECT_H
#define EFFECT_H

class PlayerModel;

class Effect
{
public:

    /*!
     * \brief contructeur Effect
     * \param player
     */
    Effect(PlayerModel &player) : player(player) {  }

    virtual ~Effect() = default;
    virtual void start(PlayerModel& player) = 0;
    virtual void stop(PlayerModel& player) = 0;

private:
    PlayerModel &player;
};

#endif // EFFECT_H
