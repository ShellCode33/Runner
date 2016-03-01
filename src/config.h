#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <map>

class Config
{
private:
    std::string filename;
    std::map<std::string, std::string> config_map;

public:
    Config(std::string filename);
    ~Config();
    void createConfig();
    void readConfig();
    std::string getSetting(std::string key);
};

#endif
