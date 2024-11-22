#include "serial_num.h"

uint8_t get_channel_number(){
    return EEPROM.read(CHAN_NUM_ADDRESS);
}

uint8_t get_down_time_number(){
    return EEPROM.read(DOWN_TIME_ADDRESS);
}