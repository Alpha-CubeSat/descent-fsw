#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

const int RxPin = 15; 
const int TxPin = 14; 

class GPSMonitor{
    private:
        bool initialized = false; 
        TinyGPSPlus gps; 
        SoftwareSerial ss; 

        // circular buffer to keep track of values 
        float prev_altitudes[10];
        int buffer_head;

        // Helper function to calculate the mean
        float calculate_mean(float arr[], int size);

        void addToBuffer(float value);

    public: 
        /*Begin reading from the sensor*/
        void execute(); 
        /* Initialize SoftwareSerial */
        GPSMonitor() ; 
        /*Checks if the sensor has been initialized */
       bool checkInitialization(); 

       float get_mean_altitude();

}; 