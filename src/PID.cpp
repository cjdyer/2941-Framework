// #include "PID.h"

// PID::PID(PID_constants _pid_constants) : m_pid_constants(_pid_constants)
// {

// }

// PID::~PID()
// {
//     stop_pid();
// }

// void PID::start_pid(const units::duration_t _timeout_ms)
// {
//     stop_pid();
//     m_handler_thread = std::thread(&PID::run_pid, this, _timeout_ms);
// }

// void PID::stop_pid()
// {
//     if (m_handler_thread.joinable())
//     {
//         m_handler_thread.join();
//     }
// }

// void PID::set_callback(pid_callback_t _callback)
// {
//     std::lock_guard<std::mutex> lck(m_pid_callback_mutex);
//     m_pid_callback = callback;
// }

// void PID::unset_callback()
// {
//     std::lock_guard<std::mutex> lck(m_pid_callback_mutex);
//     m_pid_callback = nullptr;
// }

// void PID::set_target()
// {

// }
    
// void PID::run_pid(const units::duration_t _timeout_ms)
// {
//     // PID does stuff here

//     std::lock_guard<std::mutex> lck(m_pid_callback_mutex);
//     if(m_pid_callback) { m_pid_callback(calculate()); }
// }

// int16_t PID::calculate()
// {
//     static double past_sensor_val, integral;
//     static uint64_t last_time, current_time, time_difference;
//     double sensor_value = 0.0; // m_sensor.get();

//     currentTime = pros::micros();
//     time_difference = currentTime - last_time;
//     last_time = currentTime;
    
//     error = target - sensor_value;//Calculate error.
    
//     //Calculate integral (If conditions are met).
//     integral += error * time_difference;

//     if( (abs(error) > 500/*THIS NEEDS TO NOT BE CONSTANT*/) || (error == 0) || (sgn(integral) != sgn(error)) )
//         integral = 0;
//     else if(abs(integral) > 9000)
//         integral = 9000 * sgn(integral);
    
//     derivative = (sensor_value - past_sensor_val) / time_difference;//Calculate derivative.
    
//     output = m_pid_constants.kP * error + m_pid_constants.kI * integral - m_pid_constants.kD * derivative;//Calculate output.

//     //Restrict output to max/min.
//     if (abs(output) > maxOutput)
//         output = maxOutput * sgn(output);

//     //Save previous sensor value.
//     past_sensor_val = sensor_value;
    
//     return output;
// }