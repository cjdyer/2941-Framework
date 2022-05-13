#pragma once

#include "Sensor.h"
#include "Units.h"
#include <functional>

using namespace units;

// PID
// 
// Calculate a PID value
// Be associated with an input (or multiple inputs?)
// Give an output
// Check for:
//    failing
//    Complete
//    Timeout
// Set target

using pid_callback_t = std::function<void(const int32_t)>;

struct PID_constants
{
    double kP, kI, kD;
};

class PID
{
public:
    PID(PID_constants _pid_constants, const char* _name);
    ~PID();

    void set_callback(pid_callback_t _callback);
    void unset_callback();

    void set_target(const units::distance_t _distance);

    void run_pid(void * param);

private: // functions

    int16_t calculate();
    
private: // variables
    const PID_constants m_pid_constants;
    const char* m_name;

    int32_t m_target;
    bool m_pid_running = false;
    double m_error, m_derivative;

    double max_output;

    pros::Mutex m_pid_callback_mutex;

    pid_callback_t m_pid_callback;
};