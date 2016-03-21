#ifndef CHUNK_H
#define CHUNK_H

#include <SFML/Graphics.hpp>
#include "const.h"

class Chunk : public sf::Drawable
{
public:
    Chunk(int id);
    ~Chunk();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    int pos_x;

private:
    int id; //pour les tests, à supprimer plus tard
    sf::Font font;
    sf::Text text;

};

#endif // CHUNK_H
