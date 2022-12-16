#include "framework/abstract/motor_group.h"
#include "pros/motors.h"

namespace abstract
{

MotorGroup::MotorGroup(const std::initializer_list<port_t> _ports, Gearset _gearset)
{
    m_motors.reserve(m_motors.size());

    pros::motor_gearset_e gearset = pros::E_MOTOR_GEARSET_INVALID;

    switch(_gearset)
    {
        case Gearset::RED :
            gearset = pros::E_MOTOR_GEARSET_36;
            break;
        case Gearset::GREEN :
            gearset = pros::E_MOTOR_GEARSET_18;
            break;
        case Gearset::BLUE :
            gearset = pros::E_MOTOR_GEARSET_06;
            break;
    }
    
    for (port_t port : _ports) 
    {
        m_motors.push_back(pros::Motor(abs(port), gearset, (port < 0)));
    }
}

void MotorGroup::power_motors(voltage_t _voltage)
{
    for (pros::Motor motor : m_motors)
        motor.move_voltage(_voltage.get(voltage_t::millivolt));
}

distance_t MotorGroup::get_sensor() const
{
    return m_motors.front().get_position();
}

void MotorGroup::reset_sensors()
{
    for (pros::Motor motor : m_motors)
        motor.tare_position();
}

} // namespace abstract