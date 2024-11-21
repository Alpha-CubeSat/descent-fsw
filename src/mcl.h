#include "Monitors/TempMonitor.h"
#include "Monitors/IMUMonitor.h"
#include "Monitors/GPSMonitor.h"
#include "Radio/lora.h"

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
    /**
     * Executes the loop that will read from monitors, update sfr, and print values
    */
    void execute(); 

    void checkRecovery();

MainControlLoop();
}; 