#include "TCSColorSensor.h"

TCSColorSensor::TCSColorSensor(uint8_t _S0, uint8_t _S1, uint8_t _S2, uint8_t _S3, uint8_t _sensorOut) {
  S0 = _S0;
  S1 = _S1;
  S2 = _S2;
  S3 = _S3;
  sensorOut = _sensorOut;

  redFrequency = 0;
  greenFrequency = 0;
  blueFrequency = 0;
}

void TCSColorSensor::begin() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // // Frequency scaling 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void TCSColorSensor::update() {
  // RED
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  delay(200);

  // GREEN
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  delay(200);


  // BLUE
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);
  delay(200);
}

int TCSColorSensor::getRed() { return redFrequency; }
int TCSColorSensor::getGreen() { return greenFrequency; }
int TCSColorSensor::getBlue() { return blueFrequency; }
