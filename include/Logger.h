#pragma once

#include <string>
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

struct log_info_t
{
    const char* object_name;
    const char* function_name;
};

struct Logger
{

    static std::string get_time_stamp()
    {
        std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

        std::string s(20, '\0');
        std::strftime(&s[0], s.size(), "%d-%m-%Y %X", std::localtime(&now));
        return s;
    }

    static void log(const std::string& _msg, const log_info_t& _source)
    {
        std::cout << get_time_stamp() << " " << 
            _source.object_name << "::" << _source.function_name << " " <<
            _msg.c_str() << std::endl << std::flush;
    }

}; // struct Logger