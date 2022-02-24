#pragma once
#include "main.h"
#include "units.h"

class MotorGroup
{
public:
    /**
     * @brief A DriveTrain object controls one half of your robot's chassis. (for a tank or H drive)
     * 
     * @param _motors a list of port numbers which this container should control
    **/
    MotorGroup(const port_t _motor_one, const port_t _motor_two);

    /**
     * @brief Sends specified volatage to all  motors.
     * 
     * @param _voltage The voltage to send to the motors (-12 volts to +12 volts)
    **/
    void PowerMotors(voltage_t _voltage);

    /**
     * @brief Gets the value from the front motor's encoder.
     * 
     * @return The sensor value of the first motor
    **/
    double GetSensor() const;

    /**
     * @brief 
     * 
     *
    **/
    void ResetSensors();

private:
    Motor m_motor_one;
    Motor m_motor_two;
};