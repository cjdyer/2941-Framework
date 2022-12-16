#include "framework/hardware/hardware.h"
#include "framework/config.h"

namespace hardware
{
Lift::Lift(const std::initializer_list<port_t> _motor_ports, port_t _sensor_port, 
           PID_constants _pid_constants, const char* _name) :
    m_motors(_motor_ports),
    m_height_sensor(_sensor_port), 
    m_pid(_pid_constants, _name),
    m_monitor_task(monitor_buttons),
    m_name(_name)
{
    // Logger::log("Lift Instance Created", { m_name, "Lift"});
 }


void Lift::go_to_postion(float _position)
{
    
}

void Lift::go_up()
{
    m_motors.power_motors(m_max_speed);
}

void Lift::go_down()
{
    m_motors.power_motors(m_max_speed);
}

void Lift::link_to_buttons(button_t _up_button, button_t _down_button)
{
    m_up_button   = _up_button;
    m_down_button = _down_button;
    // m_monitor_task.resume();
}

void Lift::unlink_buttons()
{
    // m_monitor_task.suspend();
}

void Lift::monitor_buttons(void* _param)
{
    uint32_t now = pros::millis();
    while(true)
    {
        // go_up(controller.get_digital(m_up_button));
        // go_down(controller.get_digital(m_down_button));
        pros::Task::delay_until(&now, 20);
    }
}

// task_t m_monitor_task;
// Mutex m_monitor_mutex;

// DistanceSensor* m_height_sensor;
// MotorGroup* m_motors;

// button_t m_up_button;
// button_t m_down_button;

} // namespace hardware