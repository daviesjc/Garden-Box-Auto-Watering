#include "../../../include/modules/waterflowSensor/WaterflowSensor.h"

#include <pigpio.h>
#include <pigpiod_if2.h>

WaterflowSensor::WaterflowSensor() {
	WATERFLOW_FREQUENCY_PIN = ConfigParser::getIntegerValue(WATERFLOW_FREQUENCY_PIN_KEY);
	PI_ID = ConfigParser::getIntegerValue(PI_ID_KEY);
	gpioSetMode(WATERFLOW_FREQUENCY_PIN, PI_INPUT);	
}

void WaterflowSensor::resetSensorCounts() {
	tickCount = 0;
	ticksPerSecond = 0;
}

void WaterflowSensor::stopRecording() {
	callback_cancel(callbackId);
}

void WaterflowSensor::resetAndRecord() {
	resetSensorCounts();
	callbackId = callback(PI_ID, WATERFLOW_FREQUENCY_PIN, RISING_EDGE, tickDetected);
}

void WaterflowSensor::calculateRollingAverage() {
	if(tickCount > 1) {
		std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        double duration_seconds = std::chrono::duration_cast<std::chrono::seconds>(now - lastTick).count();
        double frequency = 1/duration_seconds;
        ticksPerSecond = ticksPerSecond * ((tickCount - 2)/(tickCount - 1)) + (frequency/(tickCount - 1));
        lastTick = now;
   } else {
        lastTick = std::chrono::steady_clock::now();
   }
}

void WaterflowSensor::tickDetected(int pi, unsigned user_gpio, unsigned level, uint32_t tick) {
	tickCount++;
	calculateRollingAverage();
}
