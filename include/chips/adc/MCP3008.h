#include "ADC.h"

#pragma once

class MCP3008 : public ADC {
   public:
      MCP3008() : ADC();
      int readChannel(int channelNum);
};