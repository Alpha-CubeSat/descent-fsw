#include "mcl.h"
#include "sfr.h"

//TODO: Consider std deviation threshold 
void MainControlLoop::checkRecovery(){
    if (flightMode != RECOVERY && gpsMonitor.get_mean_altitude() < 5 ) {
        flightMode = RECOVERY;
    }
}

MainControlLoop::MainControlLoop(){
    flightMode = DESCENT;
}

void MainControlLoop::execute(){
    float value; 

    if (flightMode == DESCENT) {

        #ifdef VERBOSE
        Serial.println("----------START LOOP----------");
        if (tempMonitor.checkInitialization()){ 
            tempMonitor.execute(); 

            Serial.println("Temperature Values:"); 

            Serial.print("Temp C: ");
            sfr::BME280::temp_c->getValue(&value); 
            Serial.println(value);
            
            Serial.print("Pressure: ");
            sfr::BME280::pressure->getValue(&value); 
            Serial.println(value);

            Serial.flush();
        } else {
            Serial.print("Temperature Sensor not Initialized"); 
        }
        if (imuMonitor.checkInitialization()){
            imuMonitor.exceute();

            Serial.println("IMU Values: "); 

            Serial.print("Accelerometer (x,y,z) : ");

            sfr::BNO085::Acc_x->getValue(&value);
            Serial.println(value);
            sfr::BNO085::Acc_y->getValue(&value);
            Serial.println(value);
            sfr::BNO085::Acc_z->getValue(&value);
            Serial.println(value);

            Serial.print("Gyroscope (x,y,z) : ");

            sfr::BNO085::Gryo_x->getValue(&value);
            Serial.println(value);
            sfr::BNO085::Gryo_y->getValue(&value);
            Serial.println(value);
            sfr::BNO085::Gryo_z->getValue(&value);
            Serial.println(value);

            Serial.flush();
        }
        else{
            Serial.print("IMU not Initialized"); 
        }

        if (gpsMonitor.checkInitialization()){
            gpsMonitor.execute(); 

            Serial.println("GPS Values: "); 

            Serial.print("GPS Latitude: "); 

            sfr::GPS::latitude->getValue(&value); 
            Serial.println(value); 

            Serial.print("GPS Longitude: "); 

            sfr::GPS::longitude->getValue(&value); 
            Serial.println(value); 

            Serial.print("GPS Altitude: "); 

            sfr::GPS::altitude->getValue(&value); 
            Serial.println(value);

            Serial.flush();
        } else {
            Serial.print("GPS not Initialized"); 
        }
        Serial.println("----------END LOOP----------");
        
        Serial.flush();
        #endif 

        #ifndef VERBOSE 
        if (tempMonitor.checkInitialization()){ 
            tempMonitor.execute(); 

            sfr::BME280::temp_c->getValue(&value); 
            sfr::BME280::pressure->getValue(&value); 
            
        } 
        if (imuMonitor.checkInitialization()){
            imuMonitor.exceute();

            sfr::BNO085::Acc_x->getValue(&value);
            sfr::BNO085::Acc_y->getValue(&value);
            sfr::BNO085::Acc_z->getValue(&value);

            sfr::BNO085::Gryo_x->getValue(&value);
            sfr::BNO085::Gryo_y->getValue(&value);
            sfr::BNO085::Gryo_z->getValue(&value);
        }

        if (gpsMonitor.checkInitialization()){
            gpsMonitor.execute(); 
            sfr::GPS::latitude->getValue(&value); 
            sfr::GPS::longitude->getValue(&value);  
            sfr::GPS::altitude->getValue(&value); 
        } 

        loraTransmitter.addValue(sfr::BME280::temp_c);
        loraTransmitter.addValue(sfr::BME280::pressure);
        loraTransmitter.addValue(sfr::BNO085::Acc_x);
        loraTransmitter.addValue(sfr::BNO085::Acc_y);
        loraTransmitter.addValue(sfr::BNO085::Acc_z);
        loraTransmitter.addValue(sfr::BNO085::Gryo_x);
        loraTransmitter.addValue(sfr::BNO085::Gryo_y);
        loraTransmitter.addValue(sfr::BNO085::Gryo_z);
        loraTransmitter.addValue(sfr::GPS::latitude);
        loraTransmitter.addValue(sfr::GPS::longitude);
        loraTransmitter.addValue(sfr::GPS::altitude);

        loraTransmitter.Transmit();
        loraTransmitter.clearData();
        #endif

        checkRecovery();
    } else {
        // We are now in recovery mode

        // TODO: Implement a different packet that needs to be sent 
        // turn off every sensor except GPS 
    }
}