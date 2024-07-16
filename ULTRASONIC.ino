#include <Arduino.h>
#include <ULTRASONIC.h>



ULTRASONIC sensor(,);
const int counter = 5;


void setup(){
    Serial.begin(9600);
}

void loop(){

    float distance_cm = ultrasonic.get_distance(CM);
    float smoothed_distance_cm = ultrasonic.get_smoothed_distance(CM);
    
    float distance_inch = ultrasonic.get_distance(INCH);
    float smoothed_distance_inch = ultrasonic.get_smoothed_distance(INCH);

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

    float thresholod_cm = ...;
    float thresholod_inch = ...;


    bool detected_cm = sensor.objected(thresholod_cm,cm);
    bool detected_inch = sensor.objected(thresholod_inch,inch);

    if (detected_cm) {
        Serial.println("Object detected within ... cm");
    } else {
        Serial.println("No object detected within ... cm");
    }


    if (detected_inch) {
        Serial.println("Object detected within ... inch");
    } else {
        Serial.println("No object detected within ... inch");
    }


    delay(1000);
}

