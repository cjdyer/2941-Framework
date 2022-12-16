#pragma once

#include <stdint.h>

namespace Odometery
{
    extern void odo_calculate();
    extern int32_t odo_get_target_right();
    extern int32_t odo_get_target_left();
}