#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

const int RxPin = 15; 
const int TxPin = 14; 

class GPSMonitor{
    private:
        bool initialized = false; 
        TinyGPSPlus gps; 
        SoftwareSerial ss; 

        float prev_altitudes[10];

        // Helper function to calculate the mean
        float calculate_mean(float arr[], int size);

        float calculate_stddev(float arr[], int size, float mean);

    public: 
        /*Begin reading from the sensor*/
        void execute(); 
        /* Initialize SoftwareSerial */
        GPSMonitor() ; 
        /*Checks if the sensor has been initialized */
       bool checkInitialization(); 

       float get_std_dev_altitude();

}; 