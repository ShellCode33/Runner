#include "config.h"

using namespace std;

Config::Config(const string filename)
{
    this->filename = filename;
}

Config::~Config()
{

}

void Config::createConfig()
{
    fstream config_file(filename.c_str(), ios::out);

    if(config_file.is_open())
    {
        config_file << "resolution=1920x1080" << endl;
        config_file << "volume=100" << endl;
        config_file.close();
    }

    else
        cout << "Can't open config file, please check if the program is able to write into the directory" << endl;
}

void Config::readConfig()
{
    ifstream config_file(filename.c_str(), ios::in);

    if(config_file.is_open())
    {
        string line;

        while(getline(config_file, line))
        {
            string key, value;
            key = line.substr(0, line.find("="));
            value = line.substr(line.find("=")+1, line.size());
            this->config_map[key] = value;
        }

        config_file.close();
    }

    else
        createConfig();
}

string Config::getSetting(const string key)
{
    if(this->config_map.find(key) != this->config_map.end())
        return this->config_map[key];

    return "";
}
