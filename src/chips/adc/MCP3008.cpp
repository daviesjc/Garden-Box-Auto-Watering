#include "../../../include/chips/adc/MCP3008.h"

#include <iostream>
#include <pigpio.h>
#include <stdio.h>

using namespace std;

MCP3008::MCP3008() : ADC() {
   gpioSetMode(ADC_CLOCK_PIN, PI_OUTPUT);
   gpioSetMode(ADC_MISO_PIN,  PI_INPUT);
   gpioSetMode(ADC_MOSI_PIN,  PI_OUTPUT);
   gpioSetMode(ADC_CS_PIN,    PI_OUTPUT);
}

int MCP3008::readChannel(int channelNum) {
   if(channelNum > 7 || channelNum < 0) {
      std::cout << "Attempting to read channel out of range.  Attempted channel read was " << channelNum << ".  Accepted range is 0-7." << std::endl;
      return -1;
   }

   gpioWrite(ADC_CS_PIN,    PI_HIGH);
   gpioWrite(ADC_CLOCK_PIN, PI_LOW);
   gpioWrite(ADC_CS_PIN,    PI_LOW);

   int command = channelNum;
   command |= 0x18;
   command <<= 3;

   for(int i=0; i<5; i++) {
      if(command & 0x80) {
         gpioWrite(ADC_MOSI_PIN, PI_HIGH);
      } else {
         gpioWrite(ADC_MOSI_PIN, PI_LOW);
      }

      command <<= 1;
      gpioWrite(ADC_CLOCK_PIN, PI_HIGH);
      gpioWrite(ADC_CLOCK_PIN, PI_LOW);
   }

   int output = 0;
   for(int i=0; i<12; i++) {
      gpioWrite(ADC_CLOCK_PIN, PI_HIGH);
      gpioWrite(ADC_CLOCK_PIN, PI_LOW);

      output <<= 1;
      if(gpioRead(ADC_MISO_PIN)) {
         output |= 0x1;
      }
   }

   gpioWrite(ADC_CS_PIN, PI_HIGH);
   output >>= 1;
   return output;
}
