#include "../../helpers/ConfigParser.h"

#pragma once
class WaterSolenoid {
public:
    WaterSolenoid();

    virtual void open();
    virtual void close();
	
	int getOpenPin() { return WATER_SOLENOID_OPEN_PIN; }
	int getClosePin() { return WATER_SOLENOID_CLOSE_PIN; }
	
private:
	// Pins for open and close 
	int WATER_SOLENOID_OPEN_PIN = -1;
	int WATER_SOLENOID_CLOSE_PIN = -1;

    const std::string WATER_SOLENOID_OPEN_PIN_KEY = "WATER_SOLENOID_OPEN_PIN";
	const std::string WATER_SOLENOID_CLOSE_PIN_KEY = "WATER_SOLENOID_CLOSE_PIN";
};
