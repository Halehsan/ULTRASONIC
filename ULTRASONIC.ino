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
    
    float distance_inch = sensor.get_distance(inch);
    float smoothed_distance_inch = sensor.get_smoothed_distance(inch);

    Serial.print(" Distance: ");
    Serial.print(distance_cm);
    Serial.print(" cm - Smoothed Distance: ");
    Serial.print(smoothed_distance_cm);
    Serial.print(" cm\n");

    Serial.print(" Distance: ");
    Serial.print(distance_inch);
    Serial.print(" inch - Smoothed Distance: ");
    Serial.print(smoothed_distance_inch);
    Serial.println(" inch");


    // sensor.print_distance(cm);
    // sensor.print_distance(inch);


    // float dist_cm = sensor.get_distance(cm);
    // Serial.print("Distance: ");
    // Serial.print(distance_cm);
    // Serial.println(" cm");

    // float dist_inch = sensor.get_distance(inch);
    // Serial.print("Distance: ");
    // Serial.print(distance_inch);
    // Serial.println(" inch");

    float thresholod_cm = 10.0;
    float thresholod_inch = 4.0;


    bool detected_cm = sensor.object_detected(thresholod_cm,cm);
    bool detected_inch = sensor.object_detected(thresholod_inch,inch);

    if (detected_cm) {
        Serial.println("Object detected within 10 cm");
    } else {
        Serial.println("No object detected within 10 cm");
    }


    if (detected_inch) {
        Serial.println("Object detected within 4 inch");
    } else {
        Serial.println("No object detected within 4 inch");
    }


    delay(1000);
}

