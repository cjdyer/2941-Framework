#include "sensor.h"

template <typename _unit_t>
Sensor<_unit_t>::Sensor(port_t _port)
    : m_port(_port) {}

template<typename _unit_t>
void Sensor<_unit_t>::reset()
{
    offset = get();
}

template <typename _unit_t>
_unit_t Sensor<_unit_t>::get()
{
    return angle_t(read() - offset);
}

int32_t RotationSensor::read()
{
    return m_sensor.get_angle();
}

int32_t DistanceSensor::read()
{
    return m_sensor.get();
}

RotationSensor::RotationSensor(port_t _port)
    : Sensor(_port), m_sensor(pros::Rotation(_port)) {}

DistanceSensor::DistanceSensor(port_t _port)
    : Sensor(_port), m_sensor(pros::Distance(_port)) {}

Button::Button(port_t _port)
    : m_sensor(_port) {}

bool Button::get()
{
    return m_sensor.get_value();
}