#ifndef CHUNK_H
#define CHUNK_H

#include <SFML/Graphics.hpp>
#include "const.h"

class Chunk : public sf::Drawable
{
public:
    Chunk(int id);
    ~Chunk();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    int pos_x;
    void setPosition(int x);

private:
    int id; //pour les tests, à supprimer plus tard
    sf::Font font;
    sf::Text text;

    sf::Texture texture_ground;
    sf::Sprite sprite_ground;

    sf::Texture texture_background;
    sf::Sprite sprite_background;

};

#endif // CHUNK_H
