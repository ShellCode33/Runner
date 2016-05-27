/*!
 * \file config.h
 * \brief Classe utilisée pour gérer le fichier de config
 * \author Clément
 *
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <map>

class Config
{
private:
    std::string filename; /*!< Nom du fichier de config */
    std::map<std::string, std::string> config_map; /*!< Map utilisée afin de faire correspondre l'option avec sa valeur */

public:
    Config(const std::string filename);
    ~Config();
    /*!
     * \brief crée la configuration par défaut
     */
    void createConfig();

    /*!
     * \brief Se charge de lire la configuration et de tout mettre dans config_map
     */
    void readConfig();

    /*!
     * \brief Récupère la valeur correspondante à un paramètre
     * \param key : Le paramètre souhaité
     * \return La valeur du paramètre
     */
    std::string getSetting(const std::string key) const;

    /*!
     * \brief writeSetting permet d'écrire un paramètre dans le fichier de config
     * \param key
     * \param value
     */
    void writeSetting(const std::string key, const std::string value);
};

#endif // CONFIG_H
