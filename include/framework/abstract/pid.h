#pragma once

#include "framework/abstract/sensor.h"
#include "framework/units.h"

using namespace units;

// PID plan
// 
// Calculate a PID value
// Be associated with an input (or multiple inputs?)
// Give an output
// Check for:
//    failing
//    Complete
//    Timeout
// Set target

namespace abstract
{

struct PID_constants
{
    double kP, kI, kD;
    int16_t integral_calculation_start_point = 500,
    integral_max = 9000;
};

class PID
{
public:
    PID(const PID_constants& _pid_constants, const char* _name);
    ~PID() {}

    int16_t calculate(const double _sensor_value);
    
private: // variables
    const PID_constants m_pid_constants;
    const char* m_name;

    int32_t m_target;
    bool m_pid_running = false;
    double m_error, m_derivative;

    int16_t max_output = 10000;
};

} // namespace abstract