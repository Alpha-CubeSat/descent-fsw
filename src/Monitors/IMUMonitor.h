#ifndef IMU_MONITOR_H
#define IMU_MONITOR_H

#include <SparkFun_BNO080_Arduino_Library.h>

class IMUMonitor{
    private:
        // Variable to verify that the monitor was set and initializated
        bool intialized = false;

        //State variable to hold the current event of the IMU
        BNO080 sensor; 
    public:

        // Reads from IMU
        void exceute();

        // Initializes sensor 
        IMUMonitor();
        
        // Returns initialized
        bool checkInitialization(void); 

}; 

#endif 
