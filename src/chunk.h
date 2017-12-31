/*!
 * \file chunk.h
 * \class Chunk
 * \brief Classe permettant un découpage de l'écran afin de faciliter la génération aléatoire de Chunks prédéfinis
 * \author ShellCode
 */

#ifndef CHUNK_H
#define CHUNK_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "chunk_model.h"
#include "chunk_view.h"
#include "obstacle.h"
#include "coin.h"
#include "heart.h"
#include "moon.h"
#include "platform.h"
#include "magnet.h"

class Chunk
{
public:
    /*!
     * \param pos_x_default permet de définir la position par défaut du chunk sur l'écran (cette position peut-être exterieur à l'écran et le chunk peut donc ne pas être visible
     */
    Chunk(int pos_x_default, Player &player);
    virtual ~Chunk();
    virtual void update();
    ChunkModel* getModel();
    ChunkView* getView();
    /*!
     * \brief Permet d'ajouter un obstacle au modèle
     */
    void addObstacle(Obstacle* obstacle);
    void removeObstacle(Obstacle* obstacle);
    /*!
     * \brief Permet de dessiner la vue
     */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    /*!
     * \brief permet de gèrer l'apparition pseudo-aléatoire des bonus
     */
    void spawnBonusRandom();

private:
    ChunkModel model;
    ChunkView view;

    /*!
     * \brief bonus qui peuvent apparaitre dans un chunk
     */
    Heart *bonus_heart;
    Moon *bonus_moon;
    Magnet *bonus_magnet;


    Player &player;


protected:
    /*!
     * \brief contient des pointeurs vers les pièces du chunk
     */
    std::list<Coin*> coins;

    /*!
     * \brief contient des pointeurs vers les plateformes du chunk
     */
    std::list<Platform*> platforms;

};

#endif // CHUNK_H
