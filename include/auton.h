#pragma once

#include "chassis.h"
#include "pid.h"
#include "units.h"

using namespace units;
using namespace units::literals;

namespace Auton
{
    /**
     * @brief Moves the robot a set distance
     * 
     * This function waits until the movement is completed before moving on
     *  
     * @param _distance The number of encoder units to drive the robot
     * @param _maxOutput The maximum millivoltage to send to the drive motors (defaults to 12000)
    **/
    void DriveStraight(distance_t _distance, voltage_t _maxOutput = 12.0_volts);

    /**
     * @brief Moves the robot a set distance while allowing other actions to be preformed at the same time
     * 
     * This function tells the chassis to move the said distance and hands over excecution
     *  
     * @param _distance The number of encoder units to drive the robot
     * @param _maxOutput The maximum millivoltage to send to the drive motors (defaults to 12000)
    **/
    void DriveStraightAsynchronously(distance_t _distance, voltage_t _maxOutput = 12.0_volts);

    /**
     * @brief Rotates the robot a set angle
     * 
     * This function waits until the movement is completed before moving on
     * 
     * @param _angle The number of encoder units to rotate the robot
     * @param _maxOutput The maximum millivoltage to send to the drive motors (defaults to 12000)
    **/
    void Rotate(angle_t _angle, voltage_t _maxOutput = 12.0_volts);

    /**
     * @brief Rotates the robot a set angle while allowing other actions to be preformed at the same time
     * 
     * This function tells the chassis to rotate the said angle and hands over excecution
     * 
     * @param _angle The number of encoder units to rotate the robot
     * @param _maxOutput The maximum millivoltage to send to the drive motors (defaults to 12000)
    **/
    void RotateAsynchronously(angle_t _angle, voltage_t _maxOutput = 12.0_volts);

    /**
     * @brief Waits for any drive movements curretly executing to finish
    **/
    void WaitForCompletion();
};