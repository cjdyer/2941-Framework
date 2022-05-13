#include "main.h"
#include "MotorGroup.h"

pros::Controller controller(CONTROLLER_MASTER);

MotorGroup left_drive({1, -2}, Gearset::GREEN);
MotorGroup right_drive({11, -12}, Gearset::GREEN);