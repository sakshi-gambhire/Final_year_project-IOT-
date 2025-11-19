#ifndef ITDS_SENSOR_H
#define ITDS_SENSOR_H

#include "../ISensor.h"

class ITDSSensor : public ISensor {
  public:
    virtual float readTDS() = 0;
    virtual void setTemperature(float temp) = 0;
};

#endif
