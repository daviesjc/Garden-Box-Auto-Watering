#include "../../../include/modules/waterSolenoid/WaterSolenoid.h"

WaterSolenoid::WaterSolenoid() {
	WATER_SOLENOID_OPEN_PIN = ConfigParser::getIntegerValue(WATER_SOLENOID_OPEN_PIN_KEY);
	WATER_SOLENOID_CLOSE_PIN = ConfigParser::getIntegerValue(WATER_SOLENOID_CLOSE_PIN_KEY);
}