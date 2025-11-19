#ifndef IPHSENSOR_H
#define IPHSENSOR_H

#include "../ISensor.h"

class IPhSensor : public ISensor {
public:
    virtual float readPh() = 0;
};

#endif // IPHSENSOR_H
