#pragma once
#include "Units.h"

using namespace units;

template <typename _unit_t>
class Sensor
{
public:
    Sensor(port_t _port);
    ~Sensor();

    _unit_t get();
    void reset();

private:
    units::port_t m_port;
    _unit_t offset;
};

class Rotation_Sensor: Sensor<units::angle_t>
{
public:
    using Sensor<angle_t>::reset;
    using Sensor<angle_t>::get;
};

class Distance_Sensor: Sensor<units::distance_t>
{
public:
    using Sensor<distance_t>::reset;
    using Sensor<distance_t>::get;
};
