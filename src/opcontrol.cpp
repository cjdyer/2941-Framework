#include "hardware/chassis.h"
#include "config.h"
#include "abstract/sensor.h"
#include "abstract/pid.h"
#include "interface/odometery.h"

void initialize() {}
void disabled() {}
void competition_initialize() {}

void opcontrol() 
{
    while (true)
    {
        Chassis::Tank();
        
        pros::delay(20);
    }
}
