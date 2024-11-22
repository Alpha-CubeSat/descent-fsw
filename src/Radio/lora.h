#ifndef LORA_H
#define LORA_H

#include "../SensorReading.h"
#include "../sfr.h"

#define PACKET_SIZE 44
#define CHIP_SELECT 4
#define G0 3

class LORA{
    private: 
        bool initialized = false; 

        uint8_t packets_filled = 0;

        uint8_t data[PACKET_SIZE];
    public: 
        LORA(); 

        void Transmit(); 

        bool checkInitialization();

        bool addValue(SensorReading* reading); 

        void clearData();
};

#endif 