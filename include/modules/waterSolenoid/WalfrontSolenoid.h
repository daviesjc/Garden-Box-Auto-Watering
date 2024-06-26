#include "WaterSolenoid.h"

#pragma once

class WalfrontSolenoid : public WaterSolenoid {
public:
	WalfrontSolenoid() : WaterSolenoid();
	
	void open();
	void close();
};