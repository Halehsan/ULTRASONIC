#include <Arduino.h>
#include <ULTRASONIC.h>



ULTRASONIC sensor(,);

void setup(){
    Serial.begin(9600);
}

void loop(){

    float dist_cm = sensor.get_distance(cm);
    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");

    float dist_inch = sensor.get_distance(inch);
    Serial.print("Distance: ");
    Serial.print(distance_inch);
    Serial.println(" inch");

    delay(1000);
}

