#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include "mbed.h"

class ultrasonicSensor {
private:
    DigitalOut* _triggerPin;
    DigitalIn* _echoPin;
    int correction = 0;

    int readEchoPin();

    void setTriggerPin(int pinState);

    void setCorrection();

public:
    ultrasonicSensor(PinName triggerPin, PinName echoPin);

    int getDistance();
};

#endif