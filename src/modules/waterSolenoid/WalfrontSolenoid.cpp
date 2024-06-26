#include "../../../include/modules/waterSolenoid/WalfrontSolenoid.h"

#include <pigpio.h>
#include <iostream>

WalfrontSolenoid::WalfrontSolenoid() : WaterSolenoid() {
	std::cout << getOpenPin() << std::endl;
	gpioSetMode(getOpenPin(), PI_OUTPUT);
    gpioSetMode(getClosePin(), PI_OUTPUT);
	gpioSetMode(getEnablePin(), PI_OUTPUT);
}

void WalfrontSolenoid::open() {
	gpioWrite(getOpenPin(), PI_HIGH);
	gpioWrite(getEnablePin(), PI_HIGH);
	time_sleep(0.8);
	gpioWrite(getEnablePin(), PI_LOW);
	gpioWrite(getOpenPin(), PI_LOW);
}

void WalfrontSolenoid::close() {
	gpioWrite(getClosePin(), PI_HIGH);
	gpioWrite(getEnablePin(), PI_HIGH);
	time_sleep(0.8);
	gpioWrite(getEnablePin(), PI_LOW);
	gpioWrite(getClosePin(), PI_LOW);
}