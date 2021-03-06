#pragma once
#include "MotorGroup.h"
#include "Config.h"

namespace Chassis
{
    /**
     * @brief Drives the robot using tank drive controls.
     * 
     * This function needs to be constantly looped to be effective
    **/
    extern void Tank();

    /**
     * @brief Drives the robot using arcade drive controls.
     * 
     * This function needs to be constantly looped to be effective
    **/
    extern void Arcade();

    /**
     * @brief Drives the robot using single stick arcade drive controls.
     * 
     * This function needs to be constantly looped to be effective
    **/
    extern void ArcadeSingleStick();
};