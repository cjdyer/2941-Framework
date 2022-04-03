#include "MotorGroup.h"

MotorGroup::MotorGroup(const uint8_t _number_motors)
{
    m_motors.reserve(_number_motors);
}

void MotorGroup::PowerMotors(voltage_t _voltage)
{
    m_motor_one.move_voltage(_voltage.get(voltage_t::millivolt));
    m_motor_two.move_velocity(_voltage.get(voltage_t::millivolt));
}

void SetNumberOfMotors(const uint8_t _number_motors)
{

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