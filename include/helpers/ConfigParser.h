#include <stdio.h>
#include <string>
#include <map>

#pragma once

class ConfigParser {
public:
    // Read and load configuration file.
    static void loadConfigFile(std::string file);
    static void loadConfigFile(std::istream& infile);
    
    // Manually add config to the map.
    static void addConfig(std::string key, std::string value);
   
    // Get values from map in different formats.
    static std::string getStringValue(std::string key);
    static int getIntegerValue(std::string key);

private:
    static std::map<std::string, std::string> configProperties;
    const static char commentStarter = '#';
};
