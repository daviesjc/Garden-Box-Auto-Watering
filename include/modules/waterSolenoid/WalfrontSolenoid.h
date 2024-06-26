#include "WaterSolenoid.h"

#pragma once

class WalfrontSolenoid : public WaterSolenoid {
public:
	WalfrontSolenoid();
	
	void open();
	void close();
};