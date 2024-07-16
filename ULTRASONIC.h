#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

enum unit {
    cm;
    inch;
}

class ULTRASONIC{

public:

    ULTRASONIC(int triggerPin , int echoPin);
    float get_distance(unit unit::cm);
    bool object_detected(float distance_to_obj, unit unit = cm);
    void print_distance(unit unit = cm);
    float get_smoothed_distance(unit unit = cm);


private:

    float microsec_to_cm(long microsec);
    float microsec_to_inch(long microsec);
    const int triggerPin;
    const int echoPin;
    static const int counter = 5;
    float readings[counter];
    int index = 0;
    float total = 0;
    float average = 0;

    float calculate_standard_deviation(float data[], int size);


};


#endif