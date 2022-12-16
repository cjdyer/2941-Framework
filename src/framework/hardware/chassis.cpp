#include "framework/abstract/pid.h"
#include "framework/hardware/chassis.h"
#include "framework/functional/odometery.h"

#define ANALOGTOVOLTAGE 12000 / 127 * 0.97

namespace hardware
{
namespace Chassis
{

    void tank()
    {
        left_drive.power_motors(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)   * ANALOGTOVOLTAGE);
        right_drive.power_motors(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) * ANALOGTOVOLTAGE);
    }

    void arcade()
    {
        float vertical   = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        float horizontal = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

        left_drive.power_motors( (vertical + horizontal) * ANALOGTOVOLTAGE);
        right_drive.power_motors((vertical - horizontal) * ANALOGTOVOLTAGE);
    }

    void arcade_single_stick()
    {
        float vertical   = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        float horizontal = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

        left_drive.power_motors( (vertical + horizontal) * ANALOGTOVOLTAGE);
        right_drive.power_motors((vertical - horizontal) * ANALOGTOVOLTAGE);
    }

    void drive_straight_voltage(voltage_t voltage)
    {
        left_drive.power_motors(voltage);
        right_drive.power_motors(voltage);
    }

    void drive_rotate_voltage(voltage_t voltage)
    {
        left_drive.power_motors(voltage);
        right_drive.power_motors(-voltage);
    }

    void auton()
    {
        abstract::PID drive_pid = abstract::PID(drive_pid_constants, "Drive PID");

        while (!pros::Task::notify_take(true, 10)) 
        {
            // The same PID is used for both drive sides as its assumed they exist
            // as the same mechanical system. (Can rewrite when we test on a physical machine)
            int left_drive_power_mv = drive_pid.calculate(Odometery::odo_get_target_left());
            int right_drive_power_mv = drive_pid.calculate(Odometery::odo_get_target_right());
            left_drive.power_motors(left_drive_power_mv);
            right_drive.power_motors(right_drive_power_mv);
        } 
    }

} // namespace Chassis
} // namespace hardware