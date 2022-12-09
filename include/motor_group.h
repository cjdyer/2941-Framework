#pragma once

#include "units.h"
#include "pros/motors.hpp"
#include <vector>

using namespace units;

class MotorGroup
{
public:

    /**
     * @brief A DriveTrain object controls one half of your robot's chassis. (for a tank or H drive)
     * 
     * @param _ports The port of each motor
     * @param _gearset The gearset used in the motors
    **/
    MotorGroup(const std::initializer_list<port_t> _ports, Gearset _gearset = Gearset::GREEN);

    /**
     * @brief Sends specified volatage to all  motors.
     * 
     * @param _voltage The voltage to send to the motors (-12 volts to +12 volts)
    **/
    void power_motors(voltage_t _voltage);

    /**
     * @brief Gets the value from the front motor's encoder.
     * 
     * @return The sensor value of the first motor
    **/
    distance_t get_sensor() const;

    /**
     * @brief Zeros the position of the motors
     * 
     * more elaborate description here i guess
    **/
    void reset_sensors();

private:
    std::vector<pros::Motor> m_motors;
};