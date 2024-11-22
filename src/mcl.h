#ifndef MCL_H
#define MCL_H

#include "Monitors/TempMonitor.h"
#include "Monitors/IMUMonitor.h"
#include "Monitors/GPSMonitor.h"
#include "Radio/lora.h"
#include "Adafruit_SleepyDog.h"

#define WDT_RESET_TIME 4000

typedef enum FlightMode {
    DESCENT = 1, 
    RECOVERY = 2
} FlightMode;

class MainControlLoop {
    private:
        TempMonitor tempMonitor;
        IMUMonitor  imuMonitor; 
        GPSMonitor gpsMonitor; 
        LORA    loraTransmitter;

        FlightMode flightMode;
    public:
        void execute(); 

        void checkRecovery();

MainControlLoop();
}; 

#endif