#include "TempMonitor.h"
#include "sfr.h"
#include "Wire.h"

TempMonitor::TempMonitor() {

    Wire.begin();

    // If that status is false, then there was an error. 
    unsigned status = bme.begin();     
    if (!status){
        Serial.print("Can not find the Temperature sensor"); 
    } else {
        initialized = true; 
        Serial.print("Temperature Sensor Initialized");
    }
}

void TempMonitor::execute(){
    sfr::BME280::pressure->setValue(bme.readPressure() / 100.0F); 
    sfr::BME280::temp_c->setValue(bme.readTemperature()); 
}

bool TempMonitor::checkInitialization(){
    return initialized; 
}