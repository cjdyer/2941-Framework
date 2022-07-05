#include "Interfaces.h"

Lift::Lift(const std::initializer_list<port_t> _motor_ports, port_t _sensor_port, PID_constants _pid_constants, const char* _name) :
    m_motors(new MotorGroup(_motor_ports)), 
    m_height_sensor(new DistanceSensor(_sensor_port)), 
    m_pid(new PID(_pid_constants, _name))
{ }




    void go_to_postion(float _position);
    void go_up();
    void go_down();

    void link_to_buttons(button_t _up_button, button_t _down_button);
    void unlink_buttons();


    void monitor_button();

    // task_t m_monitor_task;
    // Mutex m_monitor_mutex;

    // DistanceSensor* m_height_sensor;
    // MotorGroup* m_motors;

    // button_t m_up_button;
    // button_t m_down_button;
