#include "MotorGroup.h"

MotorGroup::MotorGroup(const uint8_t _number_motors)
{
    m_motors.reserve(_number_motors);
}

void MotorGroup::PowerMotors(voltage_t _voltage)
{
    for (motor : m_motors)
        motor.move_voltage(_voltage.get(voltage_t::millivolt));
}

double MotorGroup::GetSensor() const
{
    return m_motor_one.get_position();
}

void MotorGroup::ResetSensors()
{
    for (motor : m_motors)
        motor.tare_position();
}