#include "config.h"

using namespace std;

Config::Config(string filename)
{
    this->filename = filename;
}

Config::~Config()
{

}

void Config::createConfig()
{
    fstream config_file("config", ios::out | ios::in);

    if(config_file.is_open())
    {
        config_file << "#Config File" << endl;
        config_file.close();
    }

    else
        assert("Can't open config file, please check if the program is able to write into the directory");
}

void Config::readConfig()
{
    ifstream config_file;

    if(config_file.is_open())
    {
        // TODO : Vérifier l'état de tous les paramètres dans le fichier et mettre à jour les attributs
        config_file.close();
    }

    else
        createConfig();
}
