#ifndef ICOLOR_SENSOR_H
#define ICOLOR_SENSOR_H

#include "../ISensor.h"

class IColorSensor : public ISensor {
  public:
    virtual int getRed() = 0;
    virtual int getGreen() = 0;
    virtual int getBlue() = 0;
};

#endif
