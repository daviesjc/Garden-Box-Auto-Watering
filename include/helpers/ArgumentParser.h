#include <string>

#pragma once

class ArgumentParser {
public:
	static void parseArguments(int argc, char* argv[]);
	
	const static std::string DELIMITER;
	
	const static std::string CONFIG_FILE_ARG;
	const static std::string CONFIG_FILE_KEY;
	
	const static std::string HELP_LONG_ARG;
	const static std::string HELP_SHORT_ARG;
private:
	static std::string getValue(std::string argument);
	static bool matchesArg(std::string arg, std::string longPrefix, std::string shortPrefix);
	static void printHelp();
};