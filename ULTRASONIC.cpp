#include "ULTRASONIC.h"
#include <Arduino.h>



ULTRASONIC::ULTRASONIC(int triggerPin , int echoPin){
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, OUTPUT);   
   
} 

float ULTRASONIC::get_distance(Unit unit){
    digitalWrite(triggerPin,LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin,LOW);

    float duration = pulseIn(echoPin, HIGH);

    if (unit == cm){

        return microsec_to_cm(duration);
    }else{

        return microsec_to_inch(duration);
    }
}


float ULTRASONIC::microsec_to_cm(long microsec){
    return microsec*0.0343/2;
}

float ULTRASONIC::microsec_to_inch(long microsec){
    return microsec*0.0135/2;
}

bool ULTRASONIC::object_detected(float distance_to_obj , Unit unit){
    float distance = get_distance(unit);
    return distance <= distance_to_obj;
}

void ULTRASONIC::print_distance(Unit unit) {
    float distance = get_distance(unit);

    if (unit == cm) {
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");
    } else {
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" inch");
    }
}


float ULTRASONIC::get_smoothed_distance(Unit unit) {
    float newDistance = get_distance(unit);

    readings[index] = newDistance;
    index = (index + 1) % counter;

    return get_median(readings, counter);
}

void ULTRASONIC::sort(float data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                
                float temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

float ULTRASONIC::get_median(float data[], int size) {
    float sorted[size];
    
    for (int i = 0; i < size; i++) {
        sorted[i] = data[i];
    }

    sort(sorted, size);

    if (size % 2 == 0) {
        int mid1 = size / 2 - 1;
        int mid2 = size / 2;
        return (sorted[mid1] + sorted[mid2]) / 2.0;
    } else {
        int mid = size / 2;
        return sorted[mid];
    }
}