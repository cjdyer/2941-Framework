#include "PID.h"
#include "Chassis.h"
#include "Controller.h"

#define ANALOGTOVOLTAGE 12000 / 127 * 0.97

namespace Chassis
{
    void Tank()
    {
        left_drive.power_motors(controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)   * ANALOGTOVOLTAGE);
        right_drive.power_motors(controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * ANALOGTOVOLTAGE);
    }

    void Arcade()
    {
        float vertical   = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        float horizontal = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);

        left_drive.power_motors( (vertical + horizontal) * ANALOGTOVOLTAGE);
        right_drive.power_motors((vertical - horizontal) * ANALOGTOVOLTAGE);
    }

    void ArcadeSingleStick()
    {
        float vertical   = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        float horizontal = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_X);

        left_drive.power_motors( (vertical + horizontal) * ANALOGTOVOLTAGE);
        right_drive.power_motors((vertical - horizontal) * ANALOGTOVOLTAGE);
    }
}