#include "framework/hardware/chassis.h"
#include "framework/config.h"
#include "framework/abstract/sensor.h"
#include "framework/abstract/pid.h"
#include "framework/functional/odometery.h"

using namespace hardware;

void opcontrol() 
{
    while (true)
    {
        Chassis::Tank();
        
        pros::delay(20);
    }
}
