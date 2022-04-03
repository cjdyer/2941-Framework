#include "Sensor.h"

template <type _unit_t>
Sensor<_unit_t>::Sensor(port_t _port)
    : m_port(_port) {}

void Sensor::reset()
{
    offset = get();
}

template <type _unit_t>
Sensor<_unit_t>::get()
{
    //! 0 needs to be actual value from sensor
    return angle_t(0 - offset);
}
