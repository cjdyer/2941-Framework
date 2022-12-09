#include "config.h"
#include "pros/misc.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

MotorGroup left_drive({1, -2}, Gearset::GREEN);
MotorGroup right_drive({11, -12}, Gearset::GREEN);

PID_constants drive_pid_constants = {
    0.0, 0.0, 0.0
};