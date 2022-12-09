#pragma once

#include "pros/misc.h"
#include <ostream>

enum class Gearset : int
{
    RED = 36,
    GREEN = 18,
    BLUE = 6
};

// Port_t:
// Needs to have an associated port, duh
// Needs to be assigned once?
// What if a sensor and a motor where the same

namespace units
{
    #define PI 3.14159265358979323846264338327950288419716939937510

    // typedef short distance_t;
    // typedef short voltage_t;
    // typedef short angle_t;
    // typedef long duration_t;
    typedef short port_t;
    typedef pros::controller_digital_e_t button_t;

    // Angle_t:
    // Coversion between RAD and DEG
    // Able to take both RAD and DEG inputs?
    // Stored as a DEG?
    // Automatically converts 361 deg to 1 deg?
    struct angle_t
    {
    public:
        enum angle_units: uint8_t
        {
            degrees,
            radians
        };

        angle_t(const double _a = 0, const angle_units _units = angle_units::degrees);

        double get(const angle_units _unit = degrees) const;
        void set(const double _a, const angle_units _unit = degrees);

        bool operator==(const angle_t& _a) const;
        void operator=(const angle_t& _a);
        
        angle_t operator+(const angle_t& _a) const;
        angle_t operator-(const angle_t& _a) const;
        angle_t operator*(const double _scalar) const;
        angle_t operator/(const double _scalar) const;

        void operator+=(const angle_t& _a);
        void operator-=(const angle_t& _a);
        void operator*=(const double _scalar);
        void operator/=(const double _scalar);

        bool operator>(const angle_t& _a) const;
        bool operator<(const angle_t& _a) const;
        bool operator>=(const angle_t& _a) const;
        bool operator<=(const angle_t& _a) const;

        operator double() const { return m_angle_degrees; }

    private:
        // TODO: Assess the speed difference
        // TODO: Conversion on set verse get
        double m_angle_degrees;
        double m_angle_radians;

        static constexpr double DEG_TO_RAD = PI / 180; 
        static constexpr double RAD_TO_DEG = 180 / PI; 
    };

    struct distance_t
    {
    public:
        enum distance_units : uint8_t
        {
            inch = 1,
            foot = 12,
            tile = 24   
        };
        // enum metric_units : int8_t
        // {
        //     millimetre = -3,
        //     centimetre = -2,
        //     metre = 1
        // }

        distance_t(const double _distance = 0, const distance_units _unit = inch);

        bool operator==(const distance_t& _distance) const;
        bool operator>(const distance_t& _distance) const;
        bool operator<(const distance_t& _distance) const;
        bool operator>=(const distance_t& _distance) const;
        bool operator<=(const distance_t& _distance) const;
        distance_t operator+(const distance_t& _distance) const;
        distance_t operator-(const distance_t& _distance) const;
        distance_t operator*(const double _distance) const;
        distance_t operator/(const double _distance) const;
        void operator=(const distance_t& _distance);
        void operator+=(const distance_t& _distance);
        void operator-=(const distance_t& _distance);
        void operator*=(const double _distance);
        void operator/=(const double _distance);

        operator double() const { return m_distance_inches; }

        //// friend vector_t& operator+(const angle_t& _angle, const distance_t& _distance);
        friend std::ostream& operator<<(std::ostream& _os, const distance_t& _distance);

        /**
        * @brief Gets the value of the distance object in the specified unit
        * 
        * @param _unit distance_t::units value to specify what unit the return the value uses
        **/
        double get(const distance_units& _unit) const;

        /**
        * @brief Sets the value of the distance object in the specified unit
        * 
        * @param _distance the numerical value to set the distance to
        * @param _unit distance_t::units value to specify what unit the return the value uses
        **/
        void set(const double _distance, const distance_units _unit = inch);
        
    private:
        double m_distance_inches;
    };

    struct voltage_t
    {
    public:
        enum voltage_units: uint16_t
        {
            millivolt = 1,
            volt = 1000
        };

        voltage_t(const double _voltage = 0, const voltage_units _unit = millivolt);

        bool operator==(const voltage_t& _voltage) const;
        bool operator>(const voltage_t& _voltage) const;
        bool operator<(const voltage_t& _voltage) const;
        bool operator>=(const voltage_t& _voltage) const;
        bool operator<=(const voltage_t& _voltage) const;
        voltage_t operator+(const voltage_t& _voltage) const;
        voltage_t operator-(const voltage_t& _voltage) const;
        voltage_t operator*(const double _voltage) const;
        voltage_t operator/(const double _voltage) const;
        void operator=(const voltage_t& _voltage);
        void operator+=(const voltage_t& _voltage);
        void operator-=(const voltage_t& _voltage);
        void operator*=(const double _voltage);
        void operator/=(const double _voltage);

        operator double() const { return m_voltage_millivolts; }

        friend std::ostream& operator<<(std::ostream& _os, const voltage_t& _pos);

        /**
        * @brief Gets the value of the distance object in the specified unit
        * 
        * @param A voltage_t::units value to specify what unit the return the value uses
        **/
        double get(const voltage_units& _unit) const;
        
        /**
        * @brief Sets the value of the voltage object in the specified unit
        * 
        * @param _voltage the numerical value to set the voltage to
        * @param _unit voltage_t::units value to specify what unit the return the value uses
        **/
        void set(const double _voltage, const voltage_units _unit);

    private:
        double m_voltage_millivolts;
    };

    struct duration_t
    {
    public:
        enum duration_units: uint16_t
        {
            millisecond = 1,
            second = 1000
        };

        duration_t(const double _time = 0, const duration_units _unit = millisecond);

        bool operator==(const duration_t& _time) const;
        bool operator>(const duration_t& _time) const;
        bool operator<(const duration_t& _time) const;
        bool operator>=(const duration_t& _time) const;
        bool operator<=(const duration_t& _time) const;
        duration_t operator+(const duration_t& _time) const;
        duration_t operator-(const duration_t& _time) const;
        duration_t operator*(const double _time) const;
        duration_t operator/(const double _time) const;
        void operator=(const duration_t& _time);
        void operator+=(const duration_t& _time);
        void operator-=(const duration_t& _time);
        void operator*=(const double _time);
        void operator/=(const double _time); 

        operator double() const { return m_duration_milliseconds; }

        friend std::ostream& operator<<(std::ostream& _os, const duration_t& _pos);

        /**
        * @brief Gets the value of the distance object in the specified unit
        * 
        * @param A duration_t::units value to specify what unit the return the value uses
        **/
        double get(const duration_units& _unit) const;

        /**
        * @brief Sets the value of the duration object in the specified unit
        * 
        * @param _time the numerical value to set the duration to
        * @param _unit duration_t::units value to specify what unit the return the value uses
        **/
        void set(const double _time, const duration_units _unit);

    private:
        double m_duration_milliseconds;
    };

    struct percentage_t
    {
    public:
        enum percentage_units: uint8_t
        {
            percentage = 100,
            decimal = 1
        };

        percentage_t(const double _percentage = 0, const percentage_units _unit = decimal);

        bool operator==(const percentage_t& _percentage) const;
        bool operator>(const percentage_t& _percentage) const;
        bool operator<(const percentage_t& _percentage) const;
        bool operator>=(const percentage_t& _percentage) const;
        bool operator<=(const percentage_t& _percentage) const;
        percentage_t operator+(const percentage_t& _percentage) const;
        percentage_t operator-(const percentage_t& _percentage) const;
        percentage_t operator*(const double _percentage) const;
        percentage_t operator/(const double _percentage) const;
        void operator=(const percentage_t& _percentage);
        void operator+=(const percentage_t& _percentage);
        void operator-=(const percentage_t& _percentage);
        void operator*=(const double _percentage);
        void operator/=(const double _percentage); 

        operator double() const { return m_percentage_decimal; }

        friend std::ostream& operator<<(std::ostream& _os, const percentage_t& _percentage);

        /**
        * @brief Gets the value of the distance object in the specified unit
        * 
        * @param _unit percentage_t::units value to specify what unit the return the value uses
        **/
        double get(const percentage_units& _unit) const;

        /**
        * @brief Sets the value of the percentage object in the specified unit
        * 
        * @param _percentage the numerical value to set the percentage to
        * @param _unit percentage_t::units value to specify what unit the return the value uses
        **/
        void set(const double _percentage, const percentage_units _unit);

    private:
        double m_percentage_decimal;
    };

    namespace literals
    {
        angle_t operator "" _deg(long double _angle);
        angle_t operator "" _rad(long double _angle);
        
        distance_t operator "" _inches(long double _distance);
        distance_t operator "" _feet(long double _distance);
        distance_t operator "" _tiles(long double _distance);

        voltage_t operator "" _millivolts(long double _voltage);
        voltage_t operator "" _volts(long double _voltage);
        
        duration_t operator "" _milliseconds(long double _duration);
        duration_t operator "" _seconds(long double _duration);

        percentage_t operator "" _percent(long double _percentage);
    };  // namespace literals

}; // namespace units