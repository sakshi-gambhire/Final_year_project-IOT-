#ifndef PHSENSOR_H
#define PHSENSOR_H

#include "IPhSensor.h"
#include <Arduino.h>

class PhSensor : public IPhSensor {
public:
    PhSensor(uint8_t _pin, float _calibration = 21.34);
    void begin() override;
    void update() override;
    float readPh() override;
private:
    uint8_t pin;
    float calibration;
};

#endif