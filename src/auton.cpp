#include "auton.h"
#include <cmath> 

namespace Auton
{

void ResetSensors()
{
    left_drive.reset_sensors();
    right_drive.reset_sensors();
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

void DriveStraight(distance_t _distance, percentage_t _max_output)
{
    /*
    Exact logic is in the air,
    but this function should expect a reletive distance to move
    and wait until the robot has reached its goal before finishing
    */
    int16_t forward_value = straightPID.calculate(left_drive.get_sensor());
    int16_t rotate_value = rotatePID.calculate(left_drive.get_sensor() - right_drive.get_sensor());

    // Normalization of speeds code
    // Where Forward value will be a scaled value of 1.00 
    std::sqrt(forward_value * forward_value + rotate_value * rotate_value);
    double left_value = forward_value * forward_value;

    right_drive.power_motors(forward_value + rotate_value); // 12000 + 1000^2 = 12000^2 
    right_drive.power_motors(forward_value - rotate_value); // 12000 - 1000^2 = 12000^2
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

}; // namespace Auton