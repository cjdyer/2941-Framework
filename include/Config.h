#pragma once
#include "main.h"
#include "MotorGroup.h"

// extern MotorGroup leftDrive;

enum class Gearset : int
{
    RED = 36,
    GREEN = 18,
    BLUE = 6
};

struct MotorConifg
{
    uint8_t port;
    bool reversed;
    Gearset gearing;
};

struct SensorConfig
{
    char port;
    bool reversed;
};

MotorConifg leftFrontDrive = {1, false, Gearset::GREEN};
MotorConifg leftBackDrive = {2, true, Gearset::GREEN};
MotorConifg rightFrontDrive = {9, false, Gearset::GREEN};
MotorConifg rightBackDrive = {10, true, Gearset::GREEN};

SensorConfig leftDrive = {'A', false};
SensorConfig rightDrive = {'B', false};

// Chassis::set_config({1, -2, 3, -4}, Gearset::GREEN);

