#include "main.h"

//The Vex V5 robot controller
Controller controller;


//The up (↑) button on the V5 controller
ControllerButton UpButton (ControllerDigital::up);

//The down (↓) button on the V5 controller
ControllerButton DownButton (ControllerDigital::down);

//The left (←) button on the V5 controller
ControllerButton LeftButton (ControllerDigital::left);

//The right (→) button on the V5 controller
ControllerButton RightButton (ControllerDigital::right);

//The A Button on the V5 controller
ControllerButton AButton (ControllerDigital::A);

//The B Button on the V5 controller
ControllerButton BButton (ControllerDigital::B);

//The X Button on the V5 controller
ControllerButton XButton (ControllerDigital::X);

//The Y Button on the V5 controller
ControllerButton YButton (ControllerDigital::Y);

//Top left trigger (L1) on the V5 controller
ControllerButton LeftUpTrigger (ControllerDigital::L1);

//Bottom left trigger (L2) on the V5 controller
ControllerButton LeftDownTrigger (ControllerDigital::L2);

//Top right trigger (R1) on the V5 controller
ControllerButton RightUpTrigger (ControllerDigital::R1);

//Bottom right trigger (R2) on the V5 controller
ControllerButton RightDownTrigger (ControllerDigital::R2);