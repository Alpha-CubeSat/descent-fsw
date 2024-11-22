#include "lora.h"

LORA::LORA() {

}

void LORA::Transmit() {
    if (initialized){
        // send(data, sizeof(data));
    }
}

bool LORA::addValue(SensorReading* reading){
    if (packets_filled == PACKET_SIZE){ 
        return false;
    }
    float temp;
    reading->getValue(&temp);
    memcpy(&temp, data + packets_filled, sizeof(temp));
    packets_filled += sizeof(temp);

    return true; 
}

bool LORA::checkInitialization(){
    return initialized;
}

void LORA::clearData(){
    packets_filled = 0;
}
