// Water_Solenoid.h

class WaterSolenoid {
public:
    virtual std::string open() {return "WaterSolenoid Open";}
    virtual std::string close() {return "WaterSolenoid Close";}
};
