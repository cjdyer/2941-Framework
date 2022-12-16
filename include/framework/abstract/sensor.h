#pragma once

#include "framework/units.h"
#include "pros/adi.hpp"
#include "pros/rotation.hpp"
#include "pros/distance.hpp"

using namespace units;

namespace abstract
{

template <typename _unit_t>
class Sensor
{
public:
    Sensor(port_t _port);

    _unit_t get();
    void reset();

protected:
    units::port_t m_port;
    _unit_t offset;

    virtual int32_t read();
};

class RotationSensor: Sensor<units::angle_t>
{
public:
    RotationSensor(port_t _port);

    using Sensor::Sensor;
    using Sensor::reset;
    using Sensor::get;
private:
    pros::Rotation m_sensor;

    int32_t read() override;
};

class DistanceSensor: Sensor<units::distance_t>
{
public:
    DistanceSensor(port_t _port);

    using Sensor::Sensor;
    using Sensor::reset;
    using Sensor::get;

private:
    pros::Distance m_sensor;

    int32_t read() override;
};

class Button
{
public:
    Button(port_t _port);

    bool get();

private:
    pros::ADIDigitalIn m_sensor;
};

} // namespace abstract