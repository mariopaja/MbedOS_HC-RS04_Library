#include "mbed.h"
#include "ultrasonic.h"

ultrasonicSensor::ultrasonicSensor(PinName triggerPin, PinName echoPin) : _triggerPin(new DigitalOut(triggerPin)), _echoPin(new DigitalIn(echoPin)) { setCorrection(); }

int ultrasonicSensor::readEchoPin() {
    return _echoPin->read();
}

void ultrasonicSensor::setTriggerPin(int pinState) {
    _triggerPin->write(pinState);
}

void ultrasonicSensor::setCorrection() {
    timer.reset();
    timer.start();
    while (readEchoPin() == 1) {}
    timer.stop();
    correction = timer.elapsed_time().count();
}

int ultrasonicSensor::getDistance() {
    setTriggerPin(1);
    timer.reset();
    wait_us(10.0);
    setTriggerPin(0);
    while (readEchoPin() == 0) {}
    timer.start();
    while (readEchoPin() == 1) {}
    timer.stop();
    return ((timer.elapsed_time().count() - correction) / 58);
}