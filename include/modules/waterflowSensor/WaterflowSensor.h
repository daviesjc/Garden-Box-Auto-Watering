#include <string>
#include <chrono>

#include "../../helpers/ConfigParser.h"

#pragma once

class WaterflowSensor {
public:
	WaterflowSensor();
	
	int getWaterflowPin() { return WATERFLOW_FREQUENCY_PIN; }
	
	void resetSensorCounts();
	
	void stopRecording();
	void resetAndRecord();
	
	int getTicks() { return tickCount; }
	double getTicksPerSecond() { return ticksPerSecond; }
	
	double getLitersOfWater() { return tickCount / ticksPerLiter; }
	double getLitersPerSecond() { return ticksPerSecond / ticksPerLiter; }
	
protected:
	int WATERFLOW_FREQUENCY_PIN = -1;
	int PI_ID = -1;
	
	// Variables for runtime frequency ticks
	int tickCount = 0;
	double ticksPerSecond = 0;
	
	// Last tick time
	std::chrono::steady_clock::time_point lastTick = std::chrono::steady_clock::now();
	
	// The amount of ticks for every liter of water
	double ticksPerLiter = 0;
		
	// Callback ID for waiting and reading tick counts
	int callbackId = -1;
private:
	// Calculates ticks per second
	void calculateRollingAverage();
	void tickDetected(int pi, unsigned user_gpio, unsigned level, uint32_t tick);
	
	const std::string WATERFLOW_FREQUENCY_PIN_KEY = "WATERFLOW_FREQUENCY_PIN";
	const std::string PI_ID_KEY = "PI_ID";
};