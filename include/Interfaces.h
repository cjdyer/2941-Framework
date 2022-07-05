#pragma once

#include "PID.h"
#include "Sensor.h"
#include "MotorGroup.h"
#include "Units.h"

using namespace units;
using namespace units::literals;


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
    void monitor_button(void* _param);

private:
    Task m_monitor_task(monitor_button);
    Mutex m_monitor_mutex;

    DistanceSensor m_height_sensor;
    MotorGroup m_motors;

    button_t m_up_button;
    button_t m_down_button;
    voltage_t m_max_speed = 12.0_volts;
    angle_t m_angle = 180.0_deg;

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