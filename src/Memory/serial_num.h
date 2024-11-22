#ifndef SERIAL_NUM_H
#define SERIAL_NUM_H

#include <EEPROM.h>

#define CHAN_NUM_ADDRESS 0x0
#define DOWN_TIME_ADDRESS 0x1

uint8_t get_channel_number(); 
uint8_t get_down_time_number();

#endif 