#include <atomic>

#include "chassis.h"
#include "config.h"
#include "sensor.h"
#include "pid.h"
#include "odometery.h"

void initialize() {}
void disabled() {}
void competition_initialize() {}

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

void opcontrol() 
{
    while (true)
    {
        Chassis::Tank();
        pros::delay(20);
    }
}
