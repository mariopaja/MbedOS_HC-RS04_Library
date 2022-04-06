#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H
#include "mbed.h"

class ultrasonicSensor {
private:
    DigitalOut* _triggerPin;
    DigitalIn* _echoPin;
    int correction = 0;
    Timer timer;

    int readEchoPin();

    void setTriggerPin(int pinState);

    void setCorrection();

public:
    ultrasonicSensor(PinName triggerPin, PinName echoPin);

    int getDistance();
};

#endif