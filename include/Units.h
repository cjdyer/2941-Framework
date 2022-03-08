#pragma once
#include "main.h"

// Port_t:
// Needs to have an associated port, duh
// Needs to be assigned once?

namespace units
{
    #define PI 3.14159265358979323846264338327950288419716939937510

    // typedef short distance_t;
    // typedef short voltage_t;
    // typedef short angle_t;
    // typedef long time_t;
    typedef char port_t;

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
        
        angle_t& operator+(const angle_t& _a) const;
        angle_t& operator-(const angle_t& _a) const;
        angle_t& operator*(const angle_t& _a) const;
        angle_t& operator/(const angle_t& _a) const;

        void operator+=(const angle_t& _a);
        void operator-=(const angle_t& _a);
        void operator*=(const angle_t& _a);
        void operator/=(const angle_t& _a);

        bool operator>(const angle_t& _a) const;
        bool operator<(const angle_t& _a) const;
        bool operator>=(const angle_t& _a) const;
        bool operator<=(const angle_t& _a) const;



    private:
        //TODO: Assess the speed difference
        //TODO: Conversion on set verse get
        double m_angle_degrees;
        double m_angle_radians;

        static constexpr double DEG_TO_RAD = PI / 180; 
        static constexpr double RAD_TO_DEG = 180 / PI; 
    };

    struct distance_t
    {
    public:
        enum distance_units: uint8_t
        {
            inch = 1,
            foot = 12,
            tile = 24
            // millimetre = -3,
            // centimetre = -2,
            // metre = 1
        };

        distance_t(const double _distance = 0, const distance_units = inch);

        bool operator==(const distance_t& _distance) const;
        bool operator>(const distance_t& _distance) const;
        bool operator<(const distance_t& _distance) const;
        bool operator>=(const distance_t& _distance) const;
        bool operator<=(const distance_t& _distance) const;
        distance_t& operator+(const distance_t& _distance) const;
        distance_t& operator-(const distance_t& _distance) const;
        distance_t& operator*(const distance_t& _distance) const;
        distance_t& operator/(const distance_t& _distance) const;
        void operator=(const distance_t& _distance);
        void operator+=(const distance_t& _distance);
        void operator-=(const distance_t& _distance);
        void operator*=(const distance_t& _distance);
        void operator/=(const distance_t& _distance);

        //// friend vector_t& operator+(const angle_t& _angle, const distance_t& _distance);

        /**
        * @brief Gets the value of the distance object in the specified unit
        * 
        * @param A distance_t::units value to specify what unit the return the value uses
        **/
        double get(const distance_units& _unit) const;
        
    private:
        double m_distance_inches;
    };

    struct voltage_t
    {
    public:
        enum voltage_units: uint8_t
        {
            millivolt = 1,
            volt = 1000
        };

        voltage_t(const double _voltage = 0, const voltage_units = millivolt);

        bool operator==(const voltage_t& _voltage) const;
        bool operator>(const voltage_t& _voltage) const;
        bool operator<(const voltage_t& _voltage) const;
        bool operator>=(const voltage_t& _voltage) const;
        bool operator<=(const voltage_t& _voltage) const;
        voltage_t& operator+(const voltage_t& _voltage) const;
        voltage_t& operator-(const voltage_t& _voltage) const;
        voltage_t& operator*(const voltage_t& _voltage) const;
        voltage_t& operator/(const voltage_t& _voltage) const;
        void operator=(const voltage_t& _voltage);
        void operator+=(const voltage_t& _voltage);
        void operator-=(const voltage_t& _voltage);
        void operator*=(const voltage_t& _voltage);
        void operator/=(const voltage_t& _voltage);

        /**
        * @brief Gets the value of the distance object in the specified unit
        * 
        * @param A voltage_t::units value to specify what unit the return the value uses
        **/
        double get(const voltage_units& _unit) const;

    private:
        double m_voltage_millivolts;
    };

    struct time_t
    {
    public:
        enum time_units: uint8_t
        {
            millisecond = 1,
            second = 1000
        };

        time_t(const double _time = 0, const time_units = millisecond);

        bool operator==(const time_t& _time) const;
        bool operator>(const time_t& _time) const;
        bool operator<(const time_t& _time) const;
        bool operator>=(const time_t& _time) const;
        bool operator<=(const time_t& _time) const;
        time_t& operator+(const time_t& _time) const;
        time_t& operator-(const time_t& _time) const;
        time_t& operator*(const time_t& _time) const;
        time_t& operator/(const time_t& _time) const;
        void operator=(const time_t& _time);
        void operator+=(const time_t& _time);
        void operator-=(const time_t& _time);
        void operator*=(const time_t& _time);
        void operator/=(const time_t& _time); 

        /**
        * @brief Gets the value of the distance object in the specified unit
        * 
        * @param A time_t::units value to specify what unit the return the value uses
        **/
        double get(const time_units& _unit) const;

    private:
        double m_time_milliseconds;
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
        
        time_t operator "" _milliseconds(long double _time);
        time_t operator "" _seconds(long double _time);
    }  // namespace literals

}; // namespace units