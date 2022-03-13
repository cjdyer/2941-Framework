#pragma once
#include "Units.h"

template <type _unit_t>
class Sensor
{
public:
    Sensor(port_t _port);
    ~Sensor();

    virtual _unit_t get();
    virtual void reset();

private:
    units::port_t m_port;
};

class Rotation_Sensor: Sensor<units::angle_t>
{
public:
    angle_t get() override;
    void reset() override;
};

class Distance_Sensor: Sensor<units::distance_t>
{
public:
    distance_t get() override;
    void reset() override;
};
