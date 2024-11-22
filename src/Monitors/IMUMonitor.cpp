#include "IMUMonitor.h"
#include "sfr.h"

IMUMonitor::IMUMonitor(){
  if (!sensor.begin()) {
      Serial.println("Failed to find BNO085 chip");
  }
  else {
    Serial.println("BNO085 Found!");
    intialized = true; 
  }
}

void IMUMonitor::exceute(){
    if (sensor.hasReset()) {
    Serial.print("sensor was reset ");
    }
    if(sensor.dataAvailable()){
      sfr::BNO085 :: Acc_x -> setValue(sensor.getAccelX());
      sfr::BNO085 :: Acc_y -> setValue(sensor.getAccelY());
      sfr::BNO085 :: Acc_z -> setValue(sensor.getAccelZ());
      sfr::BNO085 :: Gryo_y -> setValue(sensor.getGyroY());
      sfr::BNO085 :: Gryo_x -> setValue(sensor.getGyroX());
      sfr::BNO085 :: Gryo_z -> setValue(sensor.getGyroZ());
    }
}

bool IMUMonitor::checkInitialization(void){
    return intialized;
}
