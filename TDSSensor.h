#ifndef TDS_SENSOR_H
#define TDS_SENSOR_H

#include <Arduino.h>
#include "ITDSSensor.h"

class TDSSensor : public ITDSSensor {
  private:
    uint8_t pin;
    float VREF;
    float temperature;
    static const int SCOUNT = 30;
    int analogBuffer[SCOUNT];
    int analogBufferTemp[SCOUNT];
    int analogBufferIndex;

    int getMedianNum(int bArray[], int iFilterLen);

  public:
    TDSSensor(uint8_t _pin, float _vref = 5.0, float _temperature = 25.0);

    void begin() override;
    void update() override;
    float readTDS() override;
    void setTemperature(float temp) override;
};

#endif
