#ifndef TCS_COLOR_SENSOR_H
#define TCS_COLOR_SENSOR_H

#include <Arduino.h>
#include "IColorSensor.h"

class TCSColorSensor : public IColorSensor {
  private:
    uint8_t S0, S1, S2, S3, sensorOut;
    int redFrequency, greenFrequency, blueFrequency;

  public:
    TCSColorSensor(uint8_t _S0, uint8_t _S1, uint8_t _S2, uint8_t _S3, uint8_t _sensorOut);

    void begin() override;
    void update() override;
    int getRed() override;
    int getGreen() override;
    int getBlue() override;
};

#endif
