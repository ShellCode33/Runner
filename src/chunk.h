/*!
 * \file chunk.h
 * \class Chunk
 * \brief Classe permettant un découpage de l'écran afin de faciliter la génération aléatoire de Chunks prédéfinis
 * \author Clément
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

    void spawnBonusRandom();

private:
    ChunkModel model;
    ChunkView view;

    Heart *bonus_heart;
    Moon *bonus_moon;

    Player &player;


protected:
    std::list<Coin*> coins;
    std::list<Platform*> platforms;

};

#endif // CHUNK_H
