#include <Arduino.h>
#include "ULTRASONIC.h"



ULTRASONIC sensor(12,13);
const int counter = 5;


void setup(){
    Serial.begin(9600);
}

void loop(){

    float distance_cm = sensor.get_distance(cm);
    float smoothed_distance_cm = sensor.get_smoothed_distance(cm);
    


    Serial.print(" Distance: ");
    Serial.print(distance_cm);
    Serial.print(" cm - Smoothed Distance: ");
    Serial.print(smoothed_distance_cm);
    Serial.print(" cm\n");



    float thresholod_cm = 10.0;


    bool detected_cm = sensor.object_detected(thresholod_cm,cm);

    if (detected_cm) {
        Serial.println("Object detected within 10 cm");
    } else {
        Serial.println("No object detected within 10 cm");
    }



    int obj_count_cm = sensor.object_counter(cm);
    Serial.print("Number of machines (cm): ");
    Serial.println(obj_count_cm);

    delay(1000);
}


