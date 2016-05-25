#include "config.h"

using namespace std;

Config::Config(const string filename)
{
    this->filename = filename;
    this->readConfig();
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
        config_file << "lang=en" << endl;
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

string Config::getSetting(const string key) const
{
    if(this->config_map.find(key) != this->config_map.end())
        return this->config_map.at(key);

    return "";
}

void Config::writeSetting(const string key, const string value)
{
    ifstream config_file(filename.c_str(), ios::in);
    fstream output_file("tmp", ios::out);


    if(config_file.is_open() && output_file.is_open())
    {
        string line;

        while(getline(config_file, line))
        {
            string key_line, value_line;
            key_line = line.substr(0, line.find("="));
            value_line = line.substr(line.find("=")+1, line.size());


            if(key_line == key)
                value_line = value;

            output_file << key_line << "=" << value_line << endl;
        }

        config_file.close();
        output_file.close();

        remove(filename.c_str());
        rename("tmp", filename.c_str());

        this->config_map[key] = value;
    }

    else
        cout << "ERROR I/O" << endl;
}
