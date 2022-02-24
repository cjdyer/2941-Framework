#include "MotorContainer.h"

MotorGroup::MotorGroup(const port_t _motor_one, const port_t _motor_two)
 : m_motor_one(_motor_one), m_motor_two(_motor_two)
{
    
}

void MotorGroup::PowerMotors(voltage_t _voltage)
{
    m_motor_one.tare_position();
    m_motor_two.tare_position();
}

double MotorGroup::GetSensor() const
{
    return m_motor_one.get_position();
}

void MotorGroup::ResetSensors()
{
    m_motor_one.tare_position();
    m_motor_two.tare_position();
}