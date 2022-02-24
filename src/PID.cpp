#include "PID.h"
#include "main.h"
#include <utility>
using std::string;

// #define PID_DEBUG_OUTPUT
// #define PID_DEBUG_OUTPUT_EXTRA

#define sgn(_n) ( ((_n) > 0) * 1 + ((_n) < 0) * -1 )

PID::PID(float _kP, float _kI, float _kD, string _name)
    : name(std::move(_name)), kP(_kP), kI(_kI), kD(_kD) {}

//Returns power output for specified motor, given current sensor value.
int16_t PID::Calculate(double _sensor_value)
{
    static double pOut, iOut, dOut, output, pastSensorVal, integral;
    static uint64_t lastTime, currentTime, timeDifference;

    currentTime = pros::micros();
    timeDifference = currentTime - lastTime;
    lastTime = currentTime;
    
    error = target - _sensor_value;//Calculate error.
    
    //Calculate integral (If conditions are met).
    integral += error * timeDifference;

    if( (abs(error) > 500/*THIS NEEDS TO NOT BE CONSTANT*/) || (error == 0) || (sgn(integral) != sgn(error)) )
        integral = 0;
    else if(abs(integral) > integralLimit)
        integral = integralLimit * sgn(integral);
    
    derivative = (_sensor_value - pastSensorVal) / timeDifference;//Calculate derivative.
    
    //Calculate PID values.
    pOut = kP * error;
    iOut = kI * integral;
    dOut = kD * derivative;

    output = pOut + iOut - dOut;//Calculate output.

    //Restrict output to max/min.
    if (abs(output) > maxOutput)
        output = maxOutput * sgn(output);


    #ifdef PID_DEBUG_OUTPUT_EXTRA
    cout << name << "------------" << endl;
    cout << "Target is: " << target << endl;
    cout << "Sensor is: " << _sensor_value << endl;
    cout << "Error is: " << error << endl;
    cout << "Integral is: " << integral << endl;
    cout << "Outputting : " << output << "mV" << endl;
    #endif

    //Save previous sensor value.
    pastSensorVal = _sensor_value;
    
    return output;
}

//Returns true if robot has successfully reached its target.
bool PID::Done()
{
    uint32_t runTime = pros::millis() - startTime;

    // If error is less than a set value, then add 1 to the counter
    // If not then set the counter to 0
    errorCounter = (abs(error) < maxCompletionError) * (errorCounter + 1);
    derivativeCounter = (abs(derivative) < maxDerivativeError) * (derivativeCounter + 1);

    if(runTime > maxTime) // If movement timed out
    {
        #ifdef PID_DEBUG_OUTPUT
        cout << name << " Timed out after " << runTime << "ms, with an error of " << error << endl;
        #endif
        return true;
    }
    else if(derivativeCounter > maxDerivativeCounter)//If Robot is stuck, and unable to move (change in error was very small)
    {
        #ifdef PID_DEBUG_OUTPUT
        cout << name << "Derivative too low, unable to complete movement. Remaining error: " << error << endl;
        #endif
        return true;
    }    
    else if (errorCounter > maxErrorCounter)//If error within reasonable range
    {
        #ifdef PID_DEBUG_OUTPUT
        cout << name << " Completed with an error of " << error << endl;
        #endif
        return true;
    } 
    else return false;
}

void PID::SetTarget(int16_t _target, uint32_t _time, uint16_t _max_output)
{
    error  = 9999999;

    target = _target;
    #ifdef PID_DEBUG_OUTPUT_EXTRA
    std::cout << name << " Target Has been set to: " << _target << std::endl;
    #endif
    maxTime = _time;
    maxOutput = _max_output;
    startTime = pros::millis();
}

//Changes the set point for the PID controler
void PID::SetTarget(int16_t _target, uint16_t _max_output)
{
    // Divide revs per minute by 60,000 to get revs per millisecond
    // So no wacky (conversion) math needs to be done later when checking
    //static float ticksPerMilliSecond = ((float)motorRPM / 60.0f / 1000.0f) * (float)ticksPerRev;
    uint32_t time = 10;//(_target * 3) / ticksPerMilliSecond;

    #ifdef PID_DEBUG_OUTPUT_EXTRA
    cout << name << " time out was calculated as: " << time << endl;
    #endif

    //time (in ms) = (distance * reality factor) / (ticks per second)

    if (time < 1000) // Seems like a good idea to have some saftey for small moves
        time = 1000; // I choose 1 second at random, so feel free to adjust it

    SetTarget(_target, time, _max_output);
}

//Gets the target
int16_t PID::GetTarget() const
{
    return target;
}