#include "../../helpers/ConfigParser.h"

#pragma once
class WaterSolenoid {
public:
    WaterSolenoid() {
		WATER_SOLENOID_OPEN_PIN = ConfigParser::getIntegerValue(WATER_SOLENOID_OPEN_PIN_KEY);
		WATER_SOLENOID_CLOSE_PIN = ConfigParser::getIntegerValue(WATER_SOLENOID_CLOSE_PIN_KEY);
		WATER_SOLENOID_ENABLE_PIN = ConfigParser::getIntegerValue(WATER_SOLENOID_ENABLE_PIN_KEY);
	}

    virtual void open() { return; }
    virtual void close() { return; }
	
	int getOpenPin() { return WATER_SOLENOID_OPEN_PIN; }
	int getClosePin() { return WATER_SOLENOID_CLOSE_PIN; }
	int getEnablePin() { return WATER_SOLENOID_ENABLE_PIN; }
	
private:
	// Pins for open and close 
	int WATER_SOLENOID_OPEN_PIN = -1;
	int WATER_SOLENOID_CLOSE_PIN = -1;
	int WATER_SOLENOID_ENABLE_PIN = -1;
	
    const std::string WATER_SOLENOID_OPEN_PIN_KEY = "WATER_SOLENOID_OPEN_PIN";
	const std::string WATER_SOLENOID_CLOSE_PIN_KEY = "WATER_SOLENOID_CLOSE_PIN";
	const std::string WATER_SOLENOID_ENABLE_PIN_KEY = "WATER_SOLENOID_ENABLE_PIN"
};
