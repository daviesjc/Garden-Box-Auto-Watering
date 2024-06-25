#include "../../include/helpers/ConfigParser.h"
#include <stdio.h>
#include <string>
#include <map>
#include <fstream>
#include <iostream>

std::map<std::string, std::string> ConfigParser::configProperties;

void ConfigParser::loadConfigFile(std::string file) {
    std::ifstream configFile;
    configFile.open(file, std::ifstream::in);
    
    if(!configFile.is_open()) {
        std::cout << "Could not open config file: " << file << std::endl;
        exit(1);
    }
    
    ConfigParser::loadConfigFile(configFile);
}

void ConfigParser::loadConfigFile(std::istream& infile) {
    std::string line;
    while(std::getline(infile, line)) {
        if(!line.rfind(commentStarter, 0) == 0) {
            int index = line.find("=");
            if(index != -1) {
                std::string key = line.substr(0, index);
                line.erase(line.begin(), line.begin() + index + 1);
                std::string value = line;
                ConfigParser::configProperties.insert(std::pair<std::string, std::string>(key, value));
            }
        }
    }
}

void ConfigParser::addConfig(std::string key, std::string value) {
    ConfigParser::configProperties.insert(std::pair<std::string, std::string>(key, value));   
}

std::string ConfigParser::getStringValue(std::string key) {
    std::map<std::string, std::string>::const_iterator it = ConfigParser::configProperties.find(key);
    if(it == ConfigParser::configProperties.end()) {
        return "";
    } else {
        return it->second;
    }
}

int ConfigParser::getIntegerValue(std::string key) {
    return std::stoi(ConfigParser::getStringValue(key));   
}
