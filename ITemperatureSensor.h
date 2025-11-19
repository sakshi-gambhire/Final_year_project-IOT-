#ifndef ITEMPERATURE_SENSOR_H
#define ITEMPERATURE_SENSOR_H

#include "../ISensor.h"

class ITemperatureSensor : public ISensor {
  public:
    virtual float readCelsius() = 0;
    virtual float readFahrenheit() = 0;
};

#endif
