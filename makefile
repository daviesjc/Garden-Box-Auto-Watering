CC = g++

OUTFILE = GardenBoxWatering

build: clean
	$(CC) \
	src/main.cpp \
	src/helpers/ConfigParser.cpp \
    src/helpers/ArgumentParser.cpp \
	src/chips/adc/TestADC.cpp \
	src/modules/waterSolenoid/WalfrontSolenoid.cpp \
	src/modules/waterflowSensor/WaterflowSensor.cpp \
	src/modules/waterflowSensor/DigitenFL408.cpp \
	-o $(OUTFILE)

clean:
	rm -f $(OUTFILE)
