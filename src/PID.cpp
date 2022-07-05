#include "PID.h"

#define sgn(_n) ( ((_n) > 0) * 1 + ((_n) < 0) * -1 )

PID::PID(PID_constants _pid_constants, const char* _name)
    : m_pid_constants(_pid_constants), m_name(_name) { }

PID::~PID() { }

void PID::set_callback(pid_callback_t _callback)
{
    m_pid_callback_mutex.take(0);
    m_pid_callback = _callback;
    m_pid_callback_mutex.give();
}

void PID::unset_callback()
{
    m_pid_callback_mutex.take(0);
    m_pid_callback = nullptr;
    m_pid_callback_mutex.give();
}

void PID::set_target(distance_t _target)
{
    m_target = _target.get(units::distance_t::inch);
}
    
void PID::run_pid(void* param)
{
    // PID does stuff here
    while(m_pid_running)
    {
        int16_t output = calculate();

        {
            m_pid_callback_mutex.take(0);
            if(m_pid_callback) { m_pid_callback(output); }
            m_pid_callback_mutex.give();
        }

        pros::delay((int)param);
    }
}

int16_t PID::calculate()
{
    static double past_sensor_val, integral, output;
    static uint64_t last_time, current_time, time_difference;
    double sensor_value = 0.0; // m_sensor.get();

    current_time = pros::micros();
    time_difference = current_time - last_time;
    last_time = current_time;
    
    m_error = m_target - sensor_value; // Calculate error.
    
    // Calculate integral (If conditions are met).
    integral += m_error * time_difference;

    if( (std::abs(m_error) > 500/*THIS NEEDS TO NOT BE CONSTANT*/) || (m_error == 0) || (sgn(integral) != sgn(m_error)) )
        integral = 0;
    else if(std::abs(integral) > 9000)
        integral = 9000 * sgn(integral);
    
    m_derivative = (sensor_value - past_sensor_val) / time_difference; // Calculate derivative.
    
    output = m_pid_constants.kP * m_error + m_pid_constants.kI * integral - m_pid_constants.kD * m_derivative; // Calculate output.

    // Restrict output to max/min.
    if (std::abs(output) > max_output)
        output = max_output * sgn(output);

    // Save previous sensor value.
    past_sensor_val = sensor_value;
    
    return output;
}