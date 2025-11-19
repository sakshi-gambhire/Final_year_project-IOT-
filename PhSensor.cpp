#include "PhSensor.h"

PhSensor::PhSensor(uint8_t _pin, float _calibration) {
    pin = _pin;
    calibration = _calibration;
}

void PhSensor::begin() {
    pinMode(pin, INPUT);
}

void PhSensor::update() {
    // No continuous update needed for pH sensor
}

float PhSensor::readPh() {
    int buffer_arr[10];
    int temp;
    unsigned long avgval = 0;
    for (int i = 0; i < 10; i++) {
        buffer_arr[i] = analogRead(pin);
        delay(30);
    }
    // Sort buffer_arr
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (buffer_arr[i] > buffer_arr[j]) {
                temp = buffer_arr[i];
                buffer_arr[i] = buffer_arr[j];
                buffer_arr[j] = temp;
            }
        }
    }
    for (int i = 2; i < 8; i++) {
        avgval += buffer_arr[i];
    }
    float volt = (float)avgval * 5.0 / 1024 / 6;
    float ph_act = -5.70 * volt + calibration;
    return ph_act;
}
