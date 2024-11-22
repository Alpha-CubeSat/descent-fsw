#include "sfr.h"
#include "Memory/serial_num.h"

namespace sfr {
    namespace BME280 { 
        SensorReading *temp_c   = new SensorReading(); 
        SensorReading *pressure = new SensorReading(); 
        SensorReading *altitude = new SensorReading(); 
        SensorReading *humidity = new SensorReading(); 
    }; 

    namespace GPS {
        SensorReading *latitude = new SensorReading(); 
        SensorReading *longitude = new SensorReading(); 
        SensorReading *altitude = new SensorReading(); 

    }

    namespace LLCC68 {

    }; 

    namespace BNO085{
         SensorReading *Acc_x  = new SensorReading();
         SensorReading *Acc_y  = new SensorReading();
         SensorReading *Acc_z  = new SensorReading();
         SensorReading *Gryo_x = new SensorReading(); 
         SensorReading *Gryo_y = new SensorReading(); 
         SensorReading *Gryo_z = new SensorReading(); 
    }; 

    namespace S_NUM{
        uint8_t channel_serial_number = get_channel_number(); 
        uint8_t down_time_serial_number = get_down_time_number();
    }
}; 