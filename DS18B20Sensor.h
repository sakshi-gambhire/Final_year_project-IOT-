#ifndef DS18B20_SENSOR_H
#define DS18B20_SENSOR_H

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "ITemperatureSensor.h"

class DS18B20Sensor : public ITemperatureSensor {
  public:
    DS18B20Sensor(uint8_t pin);
    void begin() override;
    void update() override;
    float readCelsius() override;
    float readFahrenheit() override;

  private:
    uint8_t _pin;
    OneWire _oneWire;
    DallasTemperature _sensors;
};

#endif
