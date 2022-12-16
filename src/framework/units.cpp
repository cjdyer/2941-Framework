#include "units.h"

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
        duration_t operator "" _milliseconds(long double _time)
        {
            return duration_t(_time, duration_t::millisecond);
        }
        duration_t operator "" _seconds(long double _time)
        {
            return duration_t(_time, duration_t::second);
        }

        //Percentage Literals
        percentage_t operator "" _percent(long double _percentage)
        {
            return percentage_t(_percentage, percentage_t::decimal);
        }
    } // namespace literals

    angle_t::angle_t(const double _a, const angle_units _unit)
    {
        set(_a, _unit);
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
    
    angle_t angle_t::operator+(const angle_t& _a) const { return angle_t(m_angle_degrees + _a.m_angle_degrees); }
    angle_t angle_t::operator-(const angle_t& _a) const { return angle_t(m_angle_degrees - _a.m_angle_degrees); }
    angle_t angle_t::operator*(const double _scalar) const { return angle_t(m_angle_degrees * _scalar); }
    angle_t angle_t::operator/(const double _scalar) const { return angle_t(m_angle_degrees / _scalar); }
    
    void angle_t::operator=(const angle_t& _a) { set(_a.degrees); }
    void angle_t::operator+=(const angle_t& _a) { set(m_angle_degrees + _a.m_angle_degrees); }
    void angle_t::operator-=(const angle_t& _a) { set(m_angle_degrees - _a.m_angle_degrees); }
    void angle_t::operator*=(const double _scalar) { set(m_angle_degrees * _scalar); }
    void angle_t::operator/=(const double _scalar) { set(m_angle_degrees / _scalar); }
    

    //Distance----------------------------------------------------------------------------------------------------------------------------------
    distance_t::distance_t(const double _distance, const distance_units _unit)
    {
        set(_distance, _unit);
    }
    
    double distance_t::get(const distance_units& _unit) const
    {
        return m_distance_inches * _unit;
    }

    void distance_t::set(const double _distance, const distance_units _unit)
    {
        m_distance_inches = _distance * _unit;
    }
    
    bool distance_t::operator==(const distance_t& _distance) const { return m_distance_inches == _distance.m_distance_inches; }
    bool distance_t::operator>(const distance_t& _distance) const { return m_distance_inches > _distance.m_distance_inches; }
    bool distance_t::operator<(const distance_t& _distance) const { return m_distance_inches < _distance.m_distance_inches; }
    bool distance_t::operator>=(const distance_t& _distance) const { return m_distance_inches >= _distance.m_distance_inches; }
    bool distance_t::operator<=(const distance_t& _distance) const { return m_distance_inches <= _distance.m_distance_inches; }

    distance_t distance_t::operator+(const distance_t& _distance) const { return distance_t(m_distance_inches + _distance.m_distance_inches); } 
    distance_t distance_t::operator-(const distance_t& _distance) const { return distance_t(m_distance_inches - _distance.m_distance_inches); }
    distance_t distance_t::operator*(const double _scalar) const { return distance_t(m_distance_inches * _scalar); }
    distance_t distance_t::operator/(const double _scalar) const { return distance_t(m_distance_inches / _scalar); }

    void distance_t::operator=(const distance_t& _distance) { m_distance_inches = _distance.m_distance_inches; }
    void distance_t::operator+=(const distance_t& _distance) { m_distance_inches += _distance.m_distance_inches; }
    void distance_t::operator-=(const distance_t& _distance) { m_distance_inches -= _distance.m_distance_inches; }
    void distance_t::operator*=(const double _scalar) { m_distance_inches *= _scalar; }
    void distance_t::operator/=(const double _scalar) { m_distance_inches /= _scalar; }

    std::ostream& operator<<(std::ostream& _os, const distance_t& _distance)
    {
        _os << _distance.m_distance_inches << " inches";
        return _os;
    }

    //Voltage-----------------------------------------------------------------------------------------------------------------------------------
    voltage_t::voltage_t(const double _voltage, const voltage_units _unit)
    {
        set(_voltage, _unit);
    }

    double voltage_t::get(const voltage_units& _unit) const
    {
        return m_voltage_millivolts * _unit;
    }

    void voltage_t::set(const double _voltage, const voltage_units _unit)
    {
        m_voltage_millivolts = _voltage * _unit;
    }

    bool voltage_t::operator==(const voltage_t& _voltage) const { return m_voltage_millivolts == _voltage.m_voltage_millivolts; }
    bool voltage_t::operator>(const voltage_t& _voltage) const { return m_voltage_millivolts > _voltage.m_voltage_millivolts; }
    bool voltage_t::operator<(const voltage_t& _voltage) const { return m_voltage_millivolts < _voltage.m_voltage_millivolts; }
    bool voltage_t::operator>=(const voltage_t& _voltage) const { return m_voltage_millivolts >= _voltage.m_voltage_millivolts; }
    bool voltage_t::operator<=(const voltage_t& _voltage) const { return m_voltage_millivolts <= _voltage.m_voltage_millivolts; }

    voltage_t voltage_t::operator+(const voltage_t& _voltage) const { return voltage_t(m_voltage_millivolts + _voltage.m_voltage_millivolts); } 
    voltage_t voltage_t::operator-(const voltage_t& _voltage) const { return voltage_t(m_voltage_millivolts - _voltage.m_voltage_millivolts); }
    voltage_t voltage_t::operator*(const double _scalar) const { return voltage_t(m_voltage_millivolts * _scalar); }
    voltage_t voltage_t::operator/(const double _scalar) const { return voltage_t(m_voltage_millivolts / _scalar); }

    void voltage_t::operator=(const voltage_t& _voltage) { m_voltage_millivolts = _voltage.m_voltage_millivolts; }
    void voltage_t::operator+=(const voltage_t& _voltage) { m_voltage_millivolts += _voltage.m_voltage_millivolts; }
    void voltage_t::operator-=(const voltage_t& _voltage) { m_voltage_millivolts -= _voltage.m_voltage_millivolts; }
    void voltage_t::operator*=(const double _scalar) { m_voltage_millivolts *= _scalar; }
    void voltage_t::operator/=(const double _scalar) { m_voltage_millivolts /= _scalar; }

    std::ostream& operator<<(std::ostream& _os, const voltage_t& _voltage)
    {
        _os << _voltage.m_voltage_millivolts << " millivolts";
        return _os;
    }

    //Time--------------------------------------------------------------------------------------------------------------------------------------
    duration_t::duration_t(const double _time, const duration_units _unit)
    {
        m_duration_milliseconds = _time * _unit;
    }
    
    double duration_t::get(const duration_units& _unit) const
    {
        return m_duration_milliseconds * _unit;
    }

    void duration_t::set(const double _time, const duration_units _unit)
    {
        m_duration_milliseconds = _time * _unit;
    }

    bool duration_t::operator==(const duration_t& _time) const { return m_duration_milliseconds == _time.m_duration_milliseconds; }
    bool duration_t::operator>(const duration_t& _time) const { return m_duration_milliseconds > _time.m_duration_milliseconds; }
    bool duration_t::operator<(const duration_t& _time) const { return m_duration_milliseconds < _time.m_duration_milliseconds; }
    bool duration_t::operator>=(const duration_t& _time) const { return m_duration_milliseconds >= _time.m_duration_milliseconds; }
    bool duration_t::operator<=(const duration_t& _time) const { return m_duration_milliseconds <= _time.m_duration_milliseconds; }

    duration_t duration_t::operator+(const duration_t& _time) const { return duration_t(m_duration_milliseconds + _time.m_duration_milliseconds); } 
    duration_t duration_t::operator-(const duration_t& _time) const { return duration_t(m_duration_milliseconds - _time.m_duration_milliseconds); }
    duration_t duration_t::operator*(const double _scalar) const { return duration_t(m_duration_milliseconds * _scalar); }
    duration_t duration_t::operator/(const double _scalar) const { return duration_t(m_duration_milliseconds / _scalar); }

    void duration_t::operator=(const duration_t& _time) { m_duration_milliseconds = _time.m_duration_milliseconds; }
    void duration_t::operator+=(const duration_t& _time) { m_duration_milliseconds += _time.m_duration_milliseconds; }
    void duration_t::operator-=(const duration_t& _time) { m_duration_milliseconds -= _time.m_duration_milliseconds; }
    void duration_t::operator*=(const double _scalar) { m_duration_milliseconds *= _scalar; }
    void duration_t::operator/=(const double _scalar) { m_duration_milliseconds /= _scalar; }

    std::ostream& operator<<(std::ostream& _os, const duration_t& _time)
    {
        _os << _time.m_duration_milliseconds << " milliseconds";
        return _os;
    }

    //Percentage----------------------------------------------------------------------------------------------------------------------------------
    percentage_t::percentage_t(const double _percentage, const percentage_units _unit)
    {
        set(_percentage, _unit);
    }
    
    double percentage_t::get(const percentage_units& _unit) const
    {
        return m_percentage_decimal * _unit;
    }

    void percentage_t::set(const double _percentage, const percentage_units _unit)
    {
        m_percentage_decimal = _percentage * _unit;
    }
    
    bool percentage_t::operator==(const percentage_t& _percentage) const { return m_percentage_decimal == _percentage.m_percentage_decimal; }
    bool percentage_t::operator>(const percentage_t& _percentage) const { return m_percentage_decimal > _percentage.m_percentage_decimal; }
    bool percentage_t::operator<(const percentage_t& _percentage) const { return m_percentage_decimal < _percentage.m_percentage_decimal; }
    bool percentage_t::operator>=(const percentage_t& _percentage) const { return m_percentage_decimal >= _percentage.m_percentage_decimal; }
    bool percentage_t::operator<=(const percentage_t& _percentage) const { return m_percentage_decimal <= _percentage.m_percentage_decimal; }

    percentage_t percentage_t::operator+(const percentage_t& _percentage) const { return percentage_t(m_percentage_decimal + _percentage.m_percentage_decimal); } 
    percentage_t percentage_t::operator-(const percentage_t& _percentage) const { return percentage_t(m_percentage_decimal - _percentage.m_percentage_decimal); }
    percentage_t percentage_t::operator*(const double _scalar) const { return percentage_t(m_percentage_decimal * _scalar); }
    percentage_t percentage_t::operator/(const double _scalar) const { return percentage_t(m_percentage_decimal / _scalar); }

    void percentage_t::operator=(const percentage_t& _percentage) { m_percentage_decimal = _percentage.m_percentage_decimal; }
    void percentage_t::operator+=(const percentage_t& _percentage) { m_percentage_decimal += _percentage.m_percentage_decimal; }
    void percentage_t::operator-=(const percentage_t& _percentage) { m_percentage_decimal -= _percentage.m_percentage_decimal; }
    void percentage_t::operator*=(const double _scalar) { m_percentage_decimal *= _scalar; }
    void percentage_t::operator/=(const double _scalar) { m_percentage_decimal /= _scalar; }

    std::ostream& operator<<(std::ostream& _os, const percentage_t& _percentage)
    {
        _os << _percentage.m_percentage_decimal * 100 << "%";
        return _os;
    }

} // namespace units
