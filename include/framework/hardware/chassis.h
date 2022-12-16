#pragma once

#include "framework/abstract/motor_group.h"
#include "framework/config.h"

namespace hardware
{
namespace Chassis
{
    /**
     * @brief Drives the robot using tank drive controls.
     * 
     * This function needs to be constantly looped to be effective
    **/
    extern void tank();

    /**
     * @brief Drives the robot using arcade drive controls.
     * 
     * This function needs to be constantly looped to be effective
    **/
    extern void arcade();

    /**
     * @brief Drives the robot using single stick arcade drive controls.
     * 
     * This function needs to be constantly looped to be effective
    **/
    extern void arcade_single_stick();

    // Move with values
    extern void drive_straight_voltage(voltage_t voltage);

    extern void drive_rotate_voltage(voltage_t voltage);
    
} // namespace Chassis
} // namespace hardware