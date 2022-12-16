#include "interface/odometery.h"
#include "config.h"
#include <cmath> 
#include <atomic> 

void autonomous() 
{
    std::atomic<int32_t> left_drive_target(0);
    std::atomic<int32_t> right_drive_target(0);

    // details omitted for brevity
    pros::Task odo_task = pros::Task{ [] 
    {
        while (!pros::Task::notify_take(true, 2))
        {
            Odometery::odo_calculate();
        };
    } };

    pros::Task drive_task = pros::Task{ [] 
    {
        PID drive_pid = PID(drive_pid_constants, "Drive PID");

        while (!pros::Task::notify_take(true, 10)) 
        {
            // The same PID is used for both drive sides as its assumed they exist
            // as the same mechanical system. (Can rewrite when we test on a physical machine)
            int left_drive_power_mv = drive_pid.calculate(Odometery::odo_get_target_left());
            int right_drive_power_mv = drive_pid.calculate(Odometery::odo_get_target_right());
            left_drive.power_motors(left_drive_power_mv);
            right_drive.power_motors(right_drive_power_mv);
        }
    } };

    while (true) 
    {
        pros::delay(20); // What is the effect of a big delay or no delay?
    }
}

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


//     /**
//      * @brief Moves the robot a set distance
//      * 
//      * This function waits until the movement is completed before moving on
//      *  
//      * @param _distance The number of encoder units to drive the robot
//      * @param _maxOutput The maximum millivoltage to send to the drive motors (defaults to 12000)
//     **/
//     void DriveStraight(distance_t _distance, voltage_t _maxOutput = 12.0_volts);

//     /**
//      * @brief Moves the robot a set distance while allowing other actions to be preformed at the same time
//      * 
//      * This function tells the chassis to move the said distance and hands over excecution
//      *  
//      * @param _distance The number of encoder units to drive the robot
//      * @param _maxOutput The maximum millivoltage to send to the drive motors (defaults to 12000)
//     **/
//     void DriveStraightAsynchronously(distance_t _distance, voltage_t _maxOutput = 12.0_volts);

//     /**
//      * @brief Rotates the robot a set angle
//      * 
//      * This function waits until the movement is completed before moving on
//      * 
//      * @param _angle The number of encoder units to rotate the robot
//      * @param _maxOutput The maximum millivoltage to send to the drive motors (defaults to 12000)
//     **/
//     void Rotate(angle_t _angle, voltage_t _maxOutput = 12.0_volts);

//     /**
//      * @brief Rotates the robot a set angle while allowing other actions to be preformed at the same time
//      * 
//      * This function tells the chassis to rotate the said angle and hands over excecution
//      * 
//      * @param _angle The number of encoder units to rotate the robot
//      * @param _maxOutput The maximum millivoltage to send to the drive motors (defaults to 12000)
//     **/
//     void RotateAsynchronously(angle_t _angle, voltage_t _maxOutput = 12.0_volts);

//     /**
//      * @brief Waits for any drive movements curretly executing to finish
//     **/
//     void WaitForCompletion();