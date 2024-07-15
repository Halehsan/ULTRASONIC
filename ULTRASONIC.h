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

private:

    float microsec_to_cm(long microsec);
    float microsec_to_inch(long microsec);
    const int triggerPin;
    const int echoPin;

};


#endif