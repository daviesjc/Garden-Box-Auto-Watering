#include <string>
#include <chrono>

#include "../../helpers/ConfigParser.h"

#pragma once

class WaterflowSensor {
public:
	WaterflowSensor();
	
	// Methods for tracking water usage during session
	void stopRecording();
	void resetAndRecord();
	
	// Calculate liters of water
	double getLitersOfWater() { return tickCount / ticksPerLiter; }
	double getLitersPerSecond() { return ticksPerSecond / ticksPerLiter; }
		
	// Getters & Setters 
	int getCallbackId() { return callbackId; }
	int getTickCount() { return tickCount; }
	double getTicksPerSecond() { return ticksPerSecond; }
	
	double getTicksPerLiter() { return ticksPerLiter; }
	void setTicksPerLiter(int ticks) { ticksPerLiter = ticks; }
	
private:
	// Reset between sessions
	void resetSensorCounts();

	// Calculates ticks per second
	static void calculateRollingAverage();
	static void tickDetected(int pi, unsigned user_gpio, unsigned level, uint32_t tick);
	
	// Variables for callback function
	static int callbackId;
	static int tickCount;
	static double ticksPerSecond;
	static std::chrono::steady_clock::time_point lastTick;
	
	// The amount of ticks that the waterflow sensor does per liter.
	// For conversion.
	double ticksPerLiter = 0;
	
	// ConfigParser properties.
	int WATERFLOW_FREQUENCY_PIN = -1;
	int PI_ID = -1;
	
	// ConfigParser keys.
	const std::string WATERFLOW_FREQUENCY_PIN_KEY = "WATERFLOW_FREQUENCY_PIN";
	const std::string PI_ID_KEY = "PI_ID";
};