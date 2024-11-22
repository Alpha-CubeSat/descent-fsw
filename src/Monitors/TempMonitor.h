#ifndef TEMP_MONITOR_H
#define TEMP_MONITOR_H

#include <Adafruit_BME280.h>

class TempMonitor {
    private:
        bool initialized = false; 

        Adafruit_BME280 bme; 
    public: 
        // Reads from the BME280 
        void execute(); 

        // initializes sensor 
        TempMonitor(); 

        // returns initialized
        bool checkInitialization(); 
}; 

#endif 