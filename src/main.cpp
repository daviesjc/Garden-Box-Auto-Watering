/*
 * main.cpp
 *
 *  Created on: Jun 16, 2024
 *      Author: John
 */
#include <iostream>
#include <fstream>
#include "./modules/waterSolenoid/testSolenoid.cpp"
#include "../include/helpers/ConfigParser.h"
#include "../include/helpers/ArgumentParser.h"
#include "../include/chips/adc/TestADC.h"

int main(int argc, char* argv[]) {

	// Parse arguments
	ArgumentParser::parseArguments(argc, argv);

	// Set defaults if not found.
	if(ConfigParser::getStringValue(ArgumentParser::CONFIG_FILE_KEY) == "") {
	    ConfigParser::addConfig(ArgumentParser::CONFIG_FILE_KEY, "system.config");	
	}
	
	// Load config file
	std::cout << "Loading Config File: " << ConfigParser::getStringValue(ArgumentParser::CONFIG_FILE_KEY) << std::endl;
	ConfigParser::loadConfigFile(ConfigParser::getStringValue(ArgumentParser::CONFIG_FILE_KEY));
	
	// Test code for right now
	WaterSolenoid* solenoid = new testSolenoid();
	std::cout << solenoid->open() << std::endl;

	std::cout << ConfigParser::getStringValue("ADC_CLOCK_PIN") << std::endl;
	
	TestADC* adc = new TestADC();
	std::cout << adc->readChannel(1) << std::endl;
}




