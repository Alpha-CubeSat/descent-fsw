
#include "GPSMonitor.h"
#include "sfr.h"

void GPSMonitor::execute(){
    while (ss.available()){
        gps.encode(ss.read());
    }
    sfr::GPS::longitude->setValue(gps.location.lng()); 
    sfr::GPS::latitude->setValue(gps.location.lat()); 
    sfr::GPS::altitude->setValue(gps.altitude.meters());
}

GPSMonitor::GPSMonitor(): ss(RxPin,TxPin){
    ss.begin(9600); 
}

// Helper function to calculate the mean
float GPSMonitor::calculate_mean(float arr[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

float GPSMonitor::calculate_stddev(float arr[], int size, float mean) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    return sqrt(sum / size);
}

float GPSMonitor::get_std_dev_altitude(){
    return calculate_stddev(prev_altitudes, 10, calculate_mean(prev_altitudes, 10));
}

bool GPSMonitor::checkInitialization(){
    return initialized;
}