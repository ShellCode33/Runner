/*!
 * \file coin_view.h
 * \class CoinView
 * \brief Partie vue de Coin
 * \author J3ry
 */

#ifndef COIN_VIEW_H
#define COIN_VIEW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "obstacle.h"
#include "const.h"
#include "utils.h"
#include "player.h"
#include "coin_model.h"
#include "animation.h"
#include "movable.h"
#include <algorithm>
#include <utility>
#include "audio.h"

class CoinView : public Animation
{
public:
    CoinView(CoinModel &model);
    ~CoinView();
    void update();

private:
    sf::Texture coin_texture;
    CoinModel& model; /*!< Référence vers le modèle correspondant à cette vue */
    Audio sound; /*!< Son lors de la récupération de la pièce */
    bool sound_played; /*!< true lorsque la pièce a déjà joué le son de récupération */

};

#endif // COIN_VIEW_H
