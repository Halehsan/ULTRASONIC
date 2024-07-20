#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

enum Unit {
    cm,
    inch
};

class ULTRASONIC{

public:

    ULTRASONIC(int triggerPin , int echoPin);
    float get_distance(Unit unit = cm);
    bool object_detected(float distance_to_obj, Unit unit = cm);
    void print_distance(Unit unit = cm);
    float get_smoothed_distance(Unit unit = cm);
    int object_counter(Unit unit = cm);


private:

    float microsec_to_cm(unsigned long  microsec);
    float microsec_to_inch(long microsec);
    int triggerPin;
    int echoPin;
    static const int counter = 5;
    float readings[counter];
    int index = 0;
    float total = 0;
    float average = 0;

    float get_median(float data[], int size);
    void  sort(float data[], int size);

    const float detection_threshold_cm = 10.0;
    const float detection_threshold_inch = 0.393701*detection_threshold_cm ;
    bool having_obj = false;
    int obj_count = 0;
    unsigned long timeout = 500;



};


#endif