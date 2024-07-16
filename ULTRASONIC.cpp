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

bool ULTRASONIC::object_detected(float distance_to_obj , Unit unit){
    float distance = get_distance(unit);
    return distance <= distance_to_obj;
}

void print_distance(Unit unit){

    float distance = get_distance(unit);

    if (unit==cm){
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");
    }else{
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" inch");
    }
}


float ULTRASONIC::get_smoothed_distance(Unit unit) {

    float newDistance = get_distance(unit);

    readings[index] = newDistance;
    index = (index + 1) % counter;

    float total = 0;
    for (int i = 0; i < counter; i++) {
        total += readings[i];
    }

    float avg = total / counter;

    float stddev = calculate_standard_deviation(readings, counter);

    float smoothedTotal = 0;
    int count = 0;
    for (int i = 0; i < counter; i++) {
        if (fabs(readings[i] - avg) <= stddev) {
            smoothedTotal += readings[i];
            count++;
        }
    }
    if (count > 0) {
        return smoothedTotal / count;
    } else {
        return avg;
    }
}

float ULTRASONIC::calculate_standard_deviation(float data[], int size) {

    float mean = 0.0, sum_deviation = 0.0;

    for (int i = 0; i < size; ++i) {
        mean += data[i];
    }
    mean = mean / size;
    for (int i = 0; i < size; ++i) {
        sum_deviation += pow((data[i] - mean), 2);
    }
    return sqrt(sum_deviation / size);
}