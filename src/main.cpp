/*
 * main.cpp
 *
 *  Created on: Jun 16, 2024
 *      Author: John
 */
#include <iostream>
#include <fstream>
#include <pigpio.h>
#include "../include/modules/waterSolenoid/WalfrontSolenoid.h"
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

   if(gpioInitialise() == PI_INIT_FAILED) {
      std::cout << "Failed to init GPIO Interface" << std::endl;
      return 1;
   }

   int pi_id = pigpio_start(NULL, NULL);
   if(pi_id < 0) {
      std::cout << "Failed to intialize PI" << std::endl;
      return 1;
   }


	std::cout << ConfigParser::getStringValue("ADC_CLOCK_PIN") << std::endl;
	
	TestADC* adc = new TestADC();
	std::cout << adc->readChannel(1) << std::endl;
	
	// Test code for right now
	WaterSolenoid* solenoid = new WalfrontSolenoid();
	std::cout << "Opening" << std::endl;
	solenoid->open();
	
	// Test code for right now
	std::cout << "Closing" << std::endl;
	solenoid->close();
	
	   gpioTerminate();
}




