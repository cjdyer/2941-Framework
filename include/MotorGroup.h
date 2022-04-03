#pragma once
#include "main.h"
#include "Units.h"
#include <vector>
using namespace units;

class MotorGroup
{
public:
    /**
     * @brief A DriveTrain object controls one half of your robot's chassis. (for a tank or H drive)
     * 
     * @param _number_motors The amount of motors
    **/
    MotorGroup(const uint8_t _number_motors);

    /**
     * @brief Sends specified volatage to all  motors.
     * 
     * @param _voltage The voltage to send to the motors (-12 volts to +12 volts)
    **/
    void PowerMotors(voltage_t _voltage);

    /**
     * @brief Sets the ports of motors in the group.
     * 
     * ! TODO: Make this protected but able to be used by confing files
     *
     * @param _motors a list of port numbers which this container should control
    **/
    void SetNumberOfMotors(const port_t* _motors);

    /**
     * @brief Gets the value from the front motor's encoder.
     * 
     * @return The sensor value of the first motor
    **/
    distance_t GetSensor() const;

    /**
     * @brief 
     * 
     *
    **/
    void ResetSensors();

private:
    std::vector<Motor> m_motors;
};