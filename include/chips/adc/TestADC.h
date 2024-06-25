#include "ADC.h"

#pragma once

class TestADC : public ADC {
public:
	TestADC();
	int readChannel(int channelNum);
};