#include "Sensor.h"

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
    //! 0 needs to be actual value from sensor
    return angle_t(0 - offset);
}

RotationSensor::RotatationSensor()
{
    
}