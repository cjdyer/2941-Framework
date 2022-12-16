#pragma once

#include "pros/misc.hpp"
#include "framework/abstract/motor_group.h"
#include "framework/abstract/pid.h"

extern pros::Controller controller;

extern abstract::MotorGroup left_drive;
extern abstract::MotorGroup right_drive;

extern abstract::PID_constants drive_pid_constants;