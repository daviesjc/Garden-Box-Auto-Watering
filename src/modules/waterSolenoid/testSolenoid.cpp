#include "../../../include/modules/waterSolenoid/WaterSolenoid.h"
#include <iostream>

class testSolenoid: public WaterSolenoid {
public:
    std::string open() {
        return "testSolenoid Open";
    }

    std::string close() {
        return "testSolenoid Close";
    }
};
