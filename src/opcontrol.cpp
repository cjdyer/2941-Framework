#include "framework/hardware/chassis.h"
#include "framework/config.h"

using namespace hardware;

void opcontrol() 
{
    while (true)
    {
        Chassis::tank();
        
        pros::delay(20);
    }
}
