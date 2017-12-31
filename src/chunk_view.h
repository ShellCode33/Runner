/*!
 * \file chunk_view.h
 * \class ChunkView
 * \brief Partie vue des Chunk
 * \author ShellCode
 */

#ifndef CHUNK_VIEW_H
#define CHUNK_VIEW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "chunk_model.h"
#include "const.h"

class ChunkView : public sf::Drawable
{
public:
    ChunkView(ChunkModel &model);
    ~ChunkView();
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    ChunkModel &model; /*!< Référence vers le model correspondant au chunk */
    sf::Texture texture_ground[NB_THEMES]; /*! Tableau de textures de sol pour chacun des themes */
    sf::Sprite sprite_ground;

    sf::Texture texture_background[NB_THEMES];/*! Tableau de textures de background pour chacun des themes */
    sf::Sprite sprite_background;

    unsigned short actual_theme; /*!< Theme actuellement utilisé par le chunk */


};

#endif // CHUNK_VIEW_H
