#pragma once

#include "framework/abstract/pid.h"
#include "framework/abstract/sensor.h"
#include "framework/abstract/motor_group.h"
#include "framework/units.h"

using namespace units;
using namespace units::literals;
using namespace abstract;

namespace hardware
{
//! PID is not tuned
class Lift
{
public:
    Lift(const std::initializer_list<port_t> _motor_ports, port_t _sensor_port, PID_constants _pid_constants = {0, 0, 0}, const char* _name = "Lift");
    ~Lift();

    void go_to_postion(float _position);

    void go_up();
    void go_down();

    void link_to_buttons(button_t _up_button, button_t _down_button);
    void unlink_buttons();

private:
    static void monitor_buttons(void* _param);

private:
    pros::Task m_monitor_task;
    pros::Mutex m_monitor_mutex;

    DistanceSensor m_height_sensor;
    MotorGroup m_motors;

    button_t m_up_button;
    button_t m_down_button;
    voltage_t m_max_speed = 12.0_volts;

    const char* m_name;

    PID m_pid;

}; // class Lift

class Claw
{
public:
    Claw(/* args */);
    ~Claw();

private:
    RotationSensor* m_height_sensor;
    MotorGroup* m_motors;
};

class Conveyor
{
public:
    Conveyor(/* args */);
    ~Conveyor();

private:
    RotationSensor* m_height_sensor;
    MotorGroup* m_motors;
};

} // namespace hardware