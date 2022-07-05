#include "MotorGroup.h"

MotorGroup::MotorGroup(const std::initializer_list<port_t> _ports, Gearset _gearset)
{
    m_motors.reserve(m_motors.size());

    motor_gearset_e gearset = E_MOTOR_GEARSET_INVALID;

    switch(_gearset)
    {
        case Gearset::RED :
            gearset = E_MOTOR_GEARSET_36;
            break;
        case Gearset::GREEN :
            gearset = E_MOTOR_GEARSET_18;
            break;
        case Gearset::BLUE :
            gearset = E_MOTOR_GEARSET_06;
            break;
    }
    
    for (port_t port : _ports) 
    {
        m_motors.push_back(Motor(abs(port), gearset, (port < 0)));
    }
}

void MotorGroup::power_motors(voltage_t _voltage)
{
    for (Motor motor : m_motors)
        motor.move_voltage(_voltage.get(voltage_t::millivolt));
}

distance_t MotorGroup::get_sensor() const
{
    return m_motors.front().get_position();
}

void MotorGroup::reset_sensors()
{
    for (Motor motor : m_motors)
        motor.tare_position();
}