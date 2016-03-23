/*!
 * \file utils.h
 * \class Utils
 * \brief Classe utilitaire fournissant divers fonctionnalités
 * \author Clément
 *
 */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

class Utils
{
private:


public:
    Utils();
    ~Utils();

    float frand_a_b(float a, float b) const;

    /*!
     * \brief Fonction de log permettant un suivi de l'execution
     * \param text : texte qui va être affiché
     */
    static void log(const std::string text);

};

#endif //UTILS_H
