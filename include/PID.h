#pragma once

#include "Sensor.h"
#include "Units.h"
#include <functional>
#include <thread>
#include <thread>
#include <mutex>
#include <mutex>

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
    PID(PID_constants _pid_constants, const char* name);
    ~PID();

    void start_pid(const units::duration_t _timeout_ms);
    void stop_pid();

    void set_callback(pid_callback_t _callback);
    void unset_callback();

    void set_target();
    
private:
    void run_pid(const units::duration_t _timeout_ms);
    int16_t calculate();
    
private:
    PID_constants m_pid_constants;

    std::thread m_handler_thread;
    std::mutex m_pid_callback_mutex;
    pid_callback_t m_pid_callback;
};