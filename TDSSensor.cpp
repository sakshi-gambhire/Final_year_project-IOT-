#include "TDSSensor.h"

TDSSensor::TDSSensor(uint8_t _pin, float _vref, float _temperature) {
  pin = _pin;
  VREF = _vref;
  temperature = _temperature;
  analogBufferIndex = 0;
}

void TDSSensor::begin() {
  pinMode(pin, INPUT);
}

int TDSSensor::getMedianNum(int bArray[], int iFilterLen) {
  int bTab[iFilterLen];
  for (byte i = 0; i < iFilterLen; i++) bTab[i] = bArray[i];

  int i, j, bTemp;
  for (j = 0; j < iFilterLen - 1; j++)
    for (i = 0; i < iFilterLen - j - 1; i++)
      if (bTab[i] > bTab[i + 1]) {
        bTemp = bTab[i];
        bTab[i] = bTab[i + 1];
        bTab[i + 1] = bTemp;
      }

  if (iFilterLen & 1) bTemp = bTab[(iFilterLen - 1) / 2];
  else bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;

  return bTemp;
}

void TDSSensor::update() {
  analogBuffer[analogBufferIndex] = analogRead(pin);
  analogBufferIndex++;
  if (analogBufferIndex >= SCOUNT) analogBufferIndex = 0;
}

float TDSSensor::readTDS() {
  for (int i = 0; i < SCOUNT; i++) analogBufferTemp[i] = analogBuffer[i];

  float averageVoltage = getMedianNum(analogBufferTemp, SCOUNT) * VREF / 1024.0;
  float compensationVoltage = averageVoltage / (1.0 + 0.02 * (temperature - 25.0));

  return (133.42 * compensationVoltage * compensationVoltage * compensationVoltage
          - 255.86 * compensationVoltage * compensationVoltage
          + 857.39 * compensationVoltage) * 0.5;
}

void TDSSensor::setTemperature(float temp) {
  temperature = temp;
}
