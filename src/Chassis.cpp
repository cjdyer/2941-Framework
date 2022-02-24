#include "PID.h"
#include "Chassis.h"
#include "Controller.h"

#define ANALOGTOVOLTAGE 12000 / 127 * 0.97

namespace Chassis
{
    MotorGroup leftDrive (-1, 2);
    MotorGroup rightDrive (9, -10);

    void Tank()
    {
        leftDrive.PowerMotors(controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)   * ANALOGTOVOLTAGE);
        rightDrive.PowerMotors(controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * ANALOGTOVOLTAGE);
    }

    void Arcade()
    {
        float vertical   = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        float horizontal = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);

        leftDrive.PowerMotors( (vertical + horizontal) * ANALOGTOVOLTAGE);
        rightDrive.PowerMotors((vertical - horizontal) * ANALOGTOVOLTAGE);
    }

    void ArcadeSingleStick()
    {
        float vertical   = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        float horizontal = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_X);

        leftDrive.PowerMotors( (vertical + horizontal) * ANALOGTOVOLTAGE);
        rightDrive.PowerMotors((vertical - horizontal) * ANALOGTOVOLTAGE);
    }
}