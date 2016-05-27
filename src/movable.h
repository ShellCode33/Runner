/*!
 * \file movable.h
 * \class Movable
 * \brief classe modèle "primaire"
 * \author Jérémie & Clément
 *
 */

#ifndef MOVABLE_H
#define MOVABLE_H

#include <iostream>

#include "const.h"

class Movable
{
public:
    Movable(int x, int y, int w, int h);
    ~Movable();


    std::pair<float, float> getPosition() const;
    void setPosition(const std::pair<float, float> &value);

    int getX() const;
    int getY() const;

    int getHeight() const;
    void setHeight(int value);

    int getWidth() const;
    void setWidth(int value);

protected:
    std::pair<float, float> pos; /*!< pair correspondant à la position d'élément déplacable */
    int width; /*!< Largeur de l'objet */
    int height;/*!< Hauteur de l'objet */

};

#endif // MOVABLE_H
