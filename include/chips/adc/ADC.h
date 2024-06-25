#include <string>

#include "../../helpers/ConfigParser.h"

#pragma once

struct ADC {
public:
    ADC() {
    	ADC_CLOCK_PIN = ConfigParser::getIntegerValue(ADC_CLOCK_PIN_KEY);
	    ADC_MOSI_PIN  = ConfigParser::getIntegerValue(ADC_MOSI_PIN_KEY);
	    ADC_MISO_PIN  = ConfigParser::getIntegerValue(ADC_MISO_PIN_KEY);
	    ADC_CS_PIN    = ConfigParser::getIntegerValue(ADC_CS_PIN_KEY);   
    }
    
    int getClockPin() { return ADC_CLOCK_PIN; }
    int getMisoPin()  { return ADC_MISO_PIN;  }
    int getMosiPin()  { return ADC_MOSI_PIN;  }
    int getCSPin()    { return ADC_CS_PIN;    }
    
    virtual int readChannel(int channelNum) { return -1; }
    
protected:
    int ADC_CLOCK_PIN = -1;
    int ADC_MOSI_PIN  = -1;
    int ADC_MISO_PIN  = -1;
    int ADC_CS_PIN    = -1;
    
private:
    const std::string ADC_CLOCK_PIN_KEY = "ADC_CLOCK_PIN";
    const std::string ADC_MOSI_PIN_KEY  = "ADC_MOSI_PIN";
    const std::string ADC_MISO_PIN_KEY  = "ADC_MISO_PIN";
    const std::string ADC_CS_PIN_KEY    = "ADC_CS_PIN";
};
