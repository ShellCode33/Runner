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
#include <map>
#include "const.h"

#ifdef linux
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#endif

class Utils
{
private:
    //Constructeur privé : impossible d'instancier l'objet
    Utils();
    ~Utils();


public:


    static float randRange(float a, float b);

    /*!
     * \brief Fonction de log permettant un suivi de l'execution
     * \param text : texte qui va être affiché
     */
    static void log(const std::string text);
    static void addScore(unsigned long score, std::string pseudo);
    static std::vector<std::pair<unsigned long, std::string> > getScores();
    static std::vector<std::string> getAvailableLanguages();
    static std::string translate(std::string lang, std::string code);


};

#endif //UTILS_H
