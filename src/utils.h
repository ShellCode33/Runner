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
#include <fstream>
#include <climits>
#include <string.h>
#include "const.h"

class Utils
{
private:

public:
    Utils();
    ~Utils();

    static float randRange(float a, float b);

    /*!
     * \brief Fonction de log permettant un suivi de l'execution
     * \param text : texte qui va être affiché
     */
    static void log(const std::string text);
    static void addScore(unsigned long score, std::string pseudo);
    static std::pair<unsigned long, std::string>* getScores();


};

#endif //UTILS_H
