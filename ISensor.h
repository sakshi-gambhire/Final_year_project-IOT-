#ifndef ISENSOR_H
#define ISENSOR_H

class ISensor {
  public:
    virtual void begin() = 0;     // Initialize sensor
    virtual void update() = 0;    // Read/update sensor values
};

#endif
