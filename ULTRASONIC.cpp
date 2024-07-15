#include <"ULTRASONIC.h">

ULTRASONIC::ULTRASONIC(int triggerPin , int echoPin){
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    pinMode = (triggerPin, OUTPUT);
    pinMode = (echoPin, OUTPUT);   
   
} 

float ULTRASONIC::get_distance(unit unit){
    digitalWrite(triggerPin,LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin,LOW);

    duration = pulseIn(echoPin, HIGH);

    if (unit == cm){

        return microsec_to_cm(duration);
    }else{

        return microsec_to_inch(duration);
    }
}


float ULTRASONIC::microsec_to_com(long microsec){
    return microsec*0.0343/2;
}

float ULTRASONIC::microsec_to_inch(long microsec){
    return microsec*0.0135/2;
}

bool ULTRASONIC::object_detected(float distance_to_obj , unit unit){
    float distance = get_distance(unit);
    return distance <= distance_to_obj;
}
