#include "../../../include/chips/adc/TestADC.h"

TestADC::TestADC() : ADC() {}

int TestADC::readChannel(int channelNum) {
	return ADC_CLOCK_PIN;
}