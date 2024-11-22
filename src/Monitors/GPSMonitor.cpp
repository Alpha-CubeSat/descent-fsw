
#include "GPSMonitor.h"
#include "sfr.h"

void GPSMonitor::execute(){
    while (ss.available()){
        gps.encode(ss.read());
    }
    sfr::GPS::longitude->setValue(gps.location.lng()); 
    sfr::GPS::latitude->setValue(gps.location.lat()); 
    sfr::GPS::altitude->setValue(gps.altitude.meters());

    float temp;
    sfr::GPS::altitude->getValue(&temp);
    addToBuffer(temp); 
}

GPSMonitor::GPSMonitor(): ss(RxPin,TxPin){
    ss.begin(9600); 
    buffer_head = 0;
}

void GPSMonitor::addToBuffer(float value){ 
    prev_altitudes[buffer_head] = value;
    buffer_head = (buffer_head + 1) % 10;
}

// Helper function to calculate the mean
float GPSMonitor::calculate_mean(float arr[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

float GPSMonitor::get_mean_altitude(){
    return calculate_mean(prev_altitudes, 10);
}

bool GPSMonitor::checkInitialization(){
    return initialized;
}