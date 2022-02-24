#pragma once
#include <string>
#include "main.h"

class PID
{
    
    public:
        /**
         * @brief Initialize new PID object with PID constants
         *
         * @param _kP Proportional multiplier
         * @param _kI Integral multiplier
         * @param _kD Derivative multipler
         * @param _name Name of component PID is controlling
        **/
        PID (float _kP, float _kI, float _kD, std::string _name);

        /**
         * @brief Calculate power output for motor, given sensor value
         *
         * @param _sensorVal current value of affiliated sensor
         * 
         * @return The power for related motor
        **/
        int16_t Calculate(double _sensor_value);
        
        /**
         * @brief Checks to see if the PID control has finished
         * 
         * @return true is PID is completed, flase if not
        **/
        bool Done();
        
        /**
         * @brief Set a new target (set point) for the PID controller with specified time limit
         *
         * @param _target the desired finishing sensor value
         * @param _time the maximum time allowed for the movement
        **/
        void SetTarget(int16_t _target, uint32_t _time, uint16_t _max_output);

        /**
         * @brief Set a new target (set point) for the PID controller
         *
         * @param _target the desired finishing sensor value
        **/
        void SetTarget(int16_t _target, uint16_t _max_output);

        /**
         * @brief Getter function for the PID's target
         * 
         * @return the PID target
        **/
        int16_t GetTarget() const;
    
    protected:
        
    private:
        const float kP;
        const float kI;
        const float kD;

        const std::string name;
        int16_t target = 0; 
        int error;
        double derivative;

        uint8_t errorCounter;
        uint8_t derivativeCounter;
        uint8_t maxErrorCounter = 50;
        uint8_t maxDerivativeCounter = 50;

        uint32_t startTime;
        uint32_t maxTime;
        uint16_t maxOutput = 12000;

        static constexpr uint8_t minDerivative = 2;
        static constexpr uint16_t integralLimit = 5000;
        static constexpr uint8_t maxCompletionError = 10;
        static constexpr uint8_t maxDerivativeError = 10;
};