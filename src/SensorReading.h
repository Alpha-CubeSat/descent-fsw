#ifndef SENSOR_READING_H
#define SENSOR_READING_H

//Represents a sensor reading. Can update and get the current value. 
class SensorReading {
    private: 
        //Stores the current value 
        float value; 
    public: 

        void setValue(float newValue); 

        void getValue(float *changeValue); 

        SensorReading(); 
}; 

#endif