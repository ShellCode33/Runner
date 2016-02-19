#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <cassert>

class Config
{
private:
    std::string filename;

public:
    Config(std::string filename);
    ~Config();
    void createConfig();
    void readConfig();
};

#endif
