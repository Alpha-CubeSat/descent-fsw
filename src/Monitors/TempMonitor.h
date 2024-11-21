#include <Adafruit_BME280.h>

class TempMonitor {
    private:
        bool initialized = false; 

        Adafruit_BME280 bme; 
    public: 
        // Read from sensor
        void execute(); 
        // Initialize I2C Via Wire.h
        TempMonitor(); 
        // returns initialized
       bool checkInitialization(); 
}; 