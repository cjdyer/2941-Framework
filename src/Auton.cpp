#include "Auton.h"

namespace Auton
{
    void RunPID()
    {
        
    }

    void ResetSensors()
    {
        Chassis::leftDrive.ResetSensors();
        Chassis::rightDrive.ResetSensors();
    }

    PID rotatePID
    (
        {12.7, 0.3, 0},         // kP, kI, kD
        "Chassis Rotate PID"    // PIDname
    );

    PID straightPID
    (
        {17, 0.7, 0},           // kP, kI, kD
        "Chassis Straight PID"  // PIDname
    );

    void DriveStraight(distance_t _distance)
    {
        /*
        Exact logic is in the air,
        but this function should expect a reletive distance to move
        and wait until the robot has reached its goal before finishing
        */
        WaitForCompletion(/*Drive*/);
    }

    void DriveStraight(distance_t _distance, distance_t _exit_distance)
    {
        /*
        Exact logic is in the air,
        but this function should expect a reletive distance to move
        roll with it untill the _exit_distance is reached
        and summon a new thread/task to complete the action in the background
        then finish as soon as new thread has started working
        */
       
        //definitly not necessarily final, but I reckon this is about right
        // while(Chassis::leftDrive.GetSensor() < _exit_distance && Chassis::rightDrive.GetSensor() < _exit_distance)
        //     delay(1);
    }

    void Rotate(angle_t _angle)
    {
        /*
        Exact logic is in the air,
        but this function should expect a reletive angle to rotate
        and wait until the robot has reached its goal before finishing
        */
    }

    void Rotate(angle_t _angle, distance_t _exit_distance)
    {
        /*
        Exact logic is in the air,
        but this function should expect a reletive angle to rotate
        roll with it untill the _exit_distance is reached
        summon a new thread/task to complete the action in the background
        then finish as soon as new thread has started working
        */

        // definitly not necessarily final, but I reckon this is about right
        // while(Chassis::leftDrive.GetSensor() < _exit_distance && Chassis::rightDrive.GetSensor() > -(_exit_distance))
        //     delay(1);
    }
};