#include "lora.h"

LORA::LORA() : rf95(CHIP_SELECT,3) {

    pinMode(2, OUTPUT);
    digitalWrite(2, LOW);

    delay(10);

    digitalWrite(2, HIGH);
    delay(10);

    while (!Serial) ; // Wait for serial port to be available
    if (!rf95.init()) {
        initialized = true;
        #ifdef VERBOSE 
        Serial.println("init failed");
        #endif 
    } else {
        #ifdef VERBOSE 
        Serial.println("init success");
        #endif 
    }
}

void LORA::Transmit() {
    if (initialized){
        rf95.send(data, sizeof(data));
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
