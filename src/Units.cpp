#include "Units.h"

namespace units
{
    namespace literals
    {
        //Angle Literals
        angle_t operator "" _deg(long double _angle)
        {
            return angle_t(_angle, angle_t::degrees);
        }
        angle_t operator "" _rad(long double _angle)
        {
            return angle_t(_angle, angle_t::radians);
        }

        //Distance Literals
        distance_t operator "" _inches(long double _distance)
        {
            return distance_t(_distance, distance_t::inch);
        }
        distance_t operator "" _feet(long double _distance)
        {
            return distance_t(_distance, distance_t::foot);
        }
        distance_t operator "" _tiles(long double _distance)
        {
            return distance_t(_distance, distance_t::tile);
        }

        //Voltage Literals
        voltage_t operator "" _millivolts(long double _voltage)
        {
            return voltage_t(_voltage, voltage_t::millivolt);
        }
        voltage_t operator "" _volts(long double _voltage)
        {
            return voltage_t(_voltage, voltage_t::volt);
        }
        
        //Time Literals
        time_t operator "" _milliseconds(long double _time)
        {
            return time_t(_time, time_t::millisecond);
        }
        time_t operator "" _seconds(long double _time)
        {
            return time_t(_time, time_t::second);
        }
    } // namespace literals

    angle_t::angle_t(const double _a = 0, const angle_units _units = angle_units::degrees)
    {
        set(_a, _units);
    }

    double angle_t::get(const angle_units _unit) const
    {
        return m_angle_degrees * (_unit == degrees) + 
               m_angle_radians * (_unit == radians);
    }

    void angle_t::set(const double _a, const angle_units _unit)
    {
        // If units == degrees then use _a for m_angle_degrees and convert to radians for m_angle_radians
        // Vice versa for units = radians
        m_angle_degrees = _a *              (_unit == degrees) + _a * RAD_TO_DEG * (_unit == radians);
        m_angle_radians = _a * DEG_TO_RAD * (_unit == degrees) + _a *              (_unit == radians);
    }
    
    // TODO: This might need some amount of rounding to account for errors in conversions
    // TODO: I.E , 1 radians may not be equal to 57.2958 degrees due to memory limitations
    bool angle_t::operator==(const angle_t& _a) const { return m_angle_degrees == _a.m_angle_degrees; }
    bool angle_t::operator>(const angle_t& _a) const { return m_angle_degrees > _a.m_angle_degrees; }
    bool angle_t::operator<(const angle_t& _a) const { return m_angle_degrees < _a.m_angle_degrees; }
    bool angle_t::operator>=(const angle_t& _a) const { return m_angle_degrees >= _a.m_angle_degrees; }
    bool angle_t::operator<=(const angle_t& _a) const { return m_angle_degrees <= _a.m_angle_degrees; }

    // TODO: Check if we can use the void return type instead of an object reference
    
    angle_t& angle_t::operator+(const angle_t& _a) const { return angle_t(_a.m_angle_degrees + m_angle_degrees, degrees); }
    angle_t& angle_t::operator-(const angle_t& _a) const { return angle_t(m_angle_degrees - _a.m_angle_degrees, degrees); }
    angle_t& angle_t::operator*(const angle_t& _a) const { return angle_t(m_angle_degrees * _a.m_angle_degrees, degrees); }
    angle_t& angle_t::operator/(const angle_t& _a) const { return angle_t(m_angle_degrees / _a.m_angle_degrees, degrees); }
    
    void angle_t::operator=(const angle_t& _a) { set(_a.degrees); }
    void angle_t::operator+=(const angle_t& _a) { set(m_angle_degrees + _a.m_angle_degrees); }
    void angle_t::operator-=(const angle_t& _a) { set(m_angle_degrees - _a.m_angle_degrees); }
    void angle_t::operator*=(const angle_t& _a) { set(m_angle_degrees * _a.m_angle_degrees); }
    void angle_t::operator/=(const angle_t& _a) { set(m_angle_degrees / _a.m_angle_degrees); }
    

    //Distance----------------------------------------------------------------------------------------------------------------------------------
    double distance_t::get(const distance_units& _unit) const
    {
        return m_distance_inches * _unit;
    }
    
    bool distance_t::operator==(const distance_t& _distance) const { return m_distance_inches == _distance.m_distance_inches; }
    bool distance_t::operator>(const distance_t& _distance) const { return m_distance_inches > _distance.m_distance_inches; }
    bool distance_t::operator<(const distance_t& _distance) const { return m_distance_inches < _distance.m_distance_inches; }
    bool distance_t::operator>=(const distance_t& _distance) const { return m_distance_inches >= _distance.m_distance_inches; }
    bool distance_t::operator<=(const distance_t& _distance) const { return m_distance_inches <= _distance.m_distance_inches; }

    
    distance_t& distance_t::operator+(const distance_t& _distance) const { return distance_t(m_distance_inches + _distance.m_distance_inches); } 
    distance_t& distance_t::operator-(const distance_t& _distance) const { return distance_t(m_distance_inches - _distance.m_distance_inches); }
    distance_t& distance_t::operator*(const double _scalar) const { return distance_t(m_distance_inches * _scalar); }
    distance_t& distance_t::operator/(const double _scalar) const { return distance_t(m_distance_inches / _scalar); }

    void distance_t::operator=(const distance_t& _distance) { m_distance_inches = _distance.m_distance_inches; }
    void distance_t::operator+=(const distance_t& _distance) { m_distance_inches += _distance.m_distance_inches; }
    void distance_t::operator-=(const distance_t& _distance) { m_distance_inches -= _distance.m_distance_inches; }
    void distance_t::operator*=(const double _scalar) { m_distance_inches *= _scalar; }
    void distance_t::operator/=(const double _scalar) { m_distance_inches /= _scalar; }

    //Voltage-----------------------------------------------------------------------------------------------------------------------------------
    double voltage_t::get(const voltage_units& _unit) const
    {
        return m_voltage_millivolts * _unit;
    }

    bool voltage_t::operator==(const voltage_t& _voltage) const { return m_voltage_millivolts == _voltage.m_voltage_millivolts; }
    bool voltage_t::operator>(const voltage_t& _voltage) const { return m_voltage_millivolts > _voltage.m_voltage_millivolts; }
    bool voltage_t::operator<(const voltage_t& _voltage) const { return m_voltage_millivolts < _voltage.m_voltage_millivolts; }
    bool voltage_t::operator>=(const voltage_t& _voltage) const { return m_voltage_millivolts >= _voltage.m_voltage_millivolts; }
    bool voltage_t::operator<=(const voltage_t& _voltage) const { return m_voltage_millivolts <= _voltage.m_voltage_millivolts; }

    
    voltage_t& voltage_t::operator+(const voltage_t& _voltage) const { return voltage_t(m_voltage_millivolts + _voltage.m_voltage_millivolts); } 
    voltage_t& voltage_t::operator-(const voltage_t& _voltage) const { return voltage_t(m_voltage_millivolts - _voltage.m_voltage_millivolts); }
    voltage_t& voltage_t::operator*(const double _scalar) const { return voltage_t(m_voltage_millivolts * _scalar); }
    voltage_t& voltage_t::operator/(const double _scalar) const { return voltage_t(m_voltage_millivolts / _scalar); }

    void voltage_t::operator=(const voltage_t& _voltage) { m_voltage_millivolts = _voltage.m_voltage_millivolts; }
    void voltage_t::operator+=(const voltage_t& _voltage) { m_voltage_millivolts += _voltage.m_voltage_millivolts; }
    void voltage_t::operator-=(const voltage_t& _voltage) { m_voltage_millivolts -= _voltage.m_voltage_millivolts; }
    void voltage_t::operator*=(const double _scalar) { m_voltage_millivolts *= _scalar; }
    void voltage_t::operator/=(const double _scalar) { m_voltage_millivolts /= _scalar; }

    //Time--------------------------------------------------------------------------------------------------------------------------------------
    double time_t::get(const time_units& _unit) const
    {
        return m_time_milliseconds * _unit;
    }

    bool time_t::operator==(const time_t& _time) const { return m_time_milliseconds == _time.m_time_milliseconds; }
    bool time_t::operator>(const time_t& _time) const { return m_time_milliseconds > _time.m_time_milliseconds; }
    bool time_t::operator<(const time_t& _time) const { return m_time_milliseconds < _time.m_time_milliseconds; }
    bool time_t::operator>=(const time_t& _time) const { return m_time_milliseconds >= _time.m_time_milliseconds; }
    bool time_t::operator<=(const time_t& _time) const { return m_time_milliseconds <= _time.m_time_milliseconds; }

    
    time_t& time_t::operator+(const time_t& _time) const { return time_t(m_time_milliseconds + _time.m_time_milliseconds); } 
    time_t& time_t::operator-(const time_t& _time) const { return time_t(m_time_milliseconds - _time.m_time_milliseconds); }
    time_t& time_t::operator*(const double _scalar) const { return time_t(m_time_milliseconds * _scalar); }
    time_t& time_t::operator/(const double _scalar) const { return time_t(m_time_milliseconds / _scalar); }

    void time_t::operator=(const time_t& _time) { m_time_milliseconds = _time.m_time_milliseconds; }
    void time_t::operator+=(const time_t& _time) { m_time_milliseconds += _time.m_time_milliseconds; }
    void time_t::operator-=(const time_t& _time) { m_time_milliseconds -= _time.m_time_milliseconds; }
    void time_t::operator*=(const double _scalar) { m_time_milliseconds *= _scalar; }
    void time_t::operator/=(const double _scalar) { m_time_milliseconds /= _scalar; }

} // namespace units
