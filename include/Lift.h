#pragma once

#include "Sensor.h"
#include "MotorGroup.h"

class Lift
{
public:
    Lift(/* args */);
    ~Lift();

private:
    DistanceSensor m_height_sensor;
    MotorGroup m_motors;
};

