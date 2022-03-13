#include "Sensor.h"

template <type _unit_t>
Sensor<_unit_t>::Sensor(port_t _port)
    : m_port(_port) {}

angle_t Rotation_Sensor::get() 
{
    return angle_t(0);
}

void Rotation_Sensor::reset() {}

distance_t Distance_Sensor::get()
{
    return distance_t(0);
}

void Distance_Sensor::reset() {}