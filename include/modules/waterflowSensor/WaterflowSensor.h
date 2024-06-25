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
	static int WATERFLOW_FREQUENCY_PIN;
	static int PI_ID;
	
	// Variables for runtime frequency ticks
	static int tickCount;
	static double ticksPerSecond;
	
	// Last tick time
	static std::chrono::steady_clock::time_point lastTick;
	
	// The amount of ticks for every liter of water
	double ticksPerLiter = 0;
		
	// Callback ID for waiting and reading tick counts
	static int callbackId;
private:
	// Calculates ticks per second
	static void calculateRollingAverage();
	static void tickDetected(int pi, unsigned user_gpio, unsigned level, uint32_t tick);
	
	const std::string WATERFLOW_FREQUENCY_PIN_KEY = "WATERFLOW_FREQUENCY_PIN";
	const std::string PI_ID_KEY = "PI_ID";
};