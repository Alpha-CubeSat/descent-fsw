#include "serial_num.h"

uint8_t get_serial_number(){
    return EEPROM.read(S_NUM_ADDRESS);
}