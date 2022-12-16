#pragma once

#include "pros/misc.hpp"
#include "abstract/motor_group.h"
#include "abstract/pid.h"

extern pros::Controller controller;

extern MotorGroup left_drive;
extern MotorGroup right_drive;

extern PID_constants drive_pid_constants;

// Make a YAML file and read configs from that