#include "../../../include/modules/waterSolenoid/WalfrontSolenoid.h"

#include <pigpio.h>

WalfrontSolenoid::WalfrontSolenoid() : WaterSolenoid() {
	gpioSetMode(getOpenPin(), PI_OUTPUT);
    gpioSetMode(getClosePin(), PI_OUTPUT);
}

void WalfrontSolenoid::open() {
	gpioWrite(getOpenPin(), PI_HIGH);
	time_sleep(1);
	gpioWrite(getOpenPin(), PI_LOW);
}

void WalfrontSolenoid::close() {
	gpioWrite(getClosePin(), PI_HIGH);
	time_sleep(1);
	gpioWrite(getClosePin(), PI_LOW);
}