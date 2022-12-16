#include "pid.h"
#include "pros/rtos.hpp"

#define sgn(_n) ( ((_n) > 0) * 1 + ((_n) < 0) * -1 )

PID::PID(const PID_constants& _pid_constants, const char* _name)
    : m_pid_constants(_pid_constants), m_name(_name) { }

int16_t PID::calculate(const double _sensor_value)
{
    static double past_sensor_val, integral, output;
    static uint64_t last_time, current_time, time_difference;

    current_time = pros::micros();
    time_difference = current_time - last_time;
    last_time = current_time;
    
    m_error = m_target - _sensor_value; // Calculate error.
    
    // Calculate integral (If conditions are met).
    integral += m_error * time_difference;

    if( (std::abs(m_error) > m_pid_constants.integral_calculation_start_point) || (m_error == 0) || (sgn(integral) != sgn(m_error)) )
        integral = 0;
    else if(std::abs(integral) > m_pid_constants.integral_max)
        integral = m_pid_constants.integral_max * sgn(integral);
    
    m_derivative = (_sensor_value - past_sensor_val) / time_difference; // Calculate derivative.
    
    output = m_pid_constants.kP * m_error + m_pid_constants.kI * integral - m_pid_constants.kD * m_derivative; // Calculate output.

    // Restrict output to max/min.
    if (std::abs(output) > max_output)
        output = max_output * sgn(output);

    // Save previous sensor value.
    past_sensor_val = _sensor_value;
    
    return output;
}