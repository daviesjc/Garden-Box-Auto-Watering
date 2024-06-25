#include <iostream>

#include "../../include/helpers/ArgumentParser.h"
#include "../../include/helpers/ConfigParser.h"

const std::string ArgumentParser::DELIMITER = "=";

const std::string ArgumentParser::CONFIG_FILE_ARG = "--config-file";
const std::string ArgumentParser::CONFIG_FILE_KEY = "CONFIG_FILE";

const std::string ArgumentParser::HELP_LONG_ARG = "--help";
const std::string ArgumentParser::HELP_SHORT_ARG = "-h";

void ArgumentParser::parseArguments(int argc, char* argv[]) {
	// 1 here to skip reading executable name
	int index = 1;
	std::string arg = "";
	while(index < argc) {
		arg = argv[index];
		
		if(ArgumentParser::matchesArg(arg, 
									  ArgumentParser::CONFIG_FILE_ARG,
									  "")) {
			ConfigParser::addConfig(ArgumentParser::CONFIG_FILE_KEY,
									ArgumentParser::getValue(arg));
		} else if(ArgumentParser::matchesArg(arg, 
											 ArgumentParser::HELP_LONG_ARG,
											 ArgumentParser::HELP_SHORT_ARG)) {
			ArgumentParser::printHelp();
			exit(0);
		} else {
			std::cout << "Unknown Argument: " << arg << std::endl;
			exit(1);
		}
		
		index++;
	}
}

std::string ArgumentParser::getValue(std::string argument) {
	int index = argument.find(ArgumentParser::DELIMITER);
	if(index == -1) {
		return "";
	}
	
	argument.erase(argument.begin(), argument.begin() + index + 1);
	return argument;
}

bool ArgumentParser::matchesArg(std::string arg, std::string longPrefix, std::string shortPrefix) {
	// I know this sucks but its late and who actually cares
	if((arg.rfind(longPrefix, 0) == 0) && (longPrefix != "" )) {
		return true;
	} else if((arg.rfind(shortPrefix, 0) == 0) && (shortPrefix != "" )) {
		return true;	
	}
		
	return false;
}

void ArgumentParser::printHelp() {
	std::cout << "---- Garden Box Auto Watering Help Menu ----" << std::endl << std::endl;
	
	std::cout << "\t" << ArgumentParser::CONFIG_FILE_ARG << ": Path to new config file. Default is system.config in project root directory." << std::endl;
	std::cout << "\t\tUsage: " << ArgumentParser::CONFIG_FILE_ARG << ArgumentParser::DELIMITER << "/path/to/file" << std::endl;
	
	std::cout << "\t" << ArgumentParser::HELP_SHORT_ARG << ", " << ArgumentParser::HELP_LONG_ARG << ": Display help menu." << std::endl;
}