#include <Arduino.h>
#include "mcl.h"

MainControlLoop mcl; 

void setup() {
    Serial.begin(9600); 
}

void loop() {
    mcl.execute();
} 
