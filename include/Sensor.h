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

protected:
    units::port_t m_port;
    _unit_t offset;
};

class RotationSensor: Sensor<units::angle_t>
{
public:
    using Sensor::Sensor;
    using Sensor::reset;
    using Sensor::get;
private:
    pros::Rotation sensor;
};

class DistanceSensor: Sensor<units::distance_t>
{
public:
    using Sensor::Sensor;
    using Sensor::reset;
    using Sensor::get;

private:
    pros::Distance sensor;
};