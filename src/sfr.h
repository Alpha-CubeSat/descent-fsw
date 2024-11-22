#pragma once 

#include "Arduino.h"
#include "SensorReading.h"

namespace sfr {
    namespace BME280 { 
        extern SensorReading *temp_c; 
        extern SensorReading *pressure; 
    }; 

    namespace GPS {
        extern SensorReading *latitude; 
        extern SensorReading *longitude; 
        extern SensorReading *altitude; 
    }

    namespace LLCC68 {

    }; 

    namespace BNO085{
        extern SensorReading *Acc_x;
        extern SensorReading *Acc_y;
        extern SensorReading *Acc_z;
        extern SensorReading *Gryo_x;
        extern SensorReading *Gryo_y;
        extern SensorReading *Gryo_z;

    }; 

    namespace S_NUM{
        extern uint8_t channel_serial_number; 
        extern uint8_t down_time_serial_number; 
    }
}; 