#include <RH_RF95.h>
#include "../SensorReading.h"

#define PACKET_SIZE 44
#define CHIP_SELECT 4
#define G0 3

class LORA{
    private: 
        bool initialized = false; 

        uint8_t packets_filled = 0;

        RH_RF95 rf95;

        uint8_t data[PACKET_SIZE];
    public: 
        // initializes the radio module
        LORA(); 
        // Transmits 
        void Transmit(); 
        // returns initialized
        bool checkInitialization();

        // Adds value to the data. Increments the packets_filled by 1. If the 
        // packets_filled has reached PACKET_SIZE, we do not perform the add.
        // Returns true if successfully added
        bool addValue(SensorReading* reading); 

        void clearData();
};
