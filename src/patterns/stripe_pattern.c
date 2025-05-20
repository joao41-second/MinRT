#include "pattern.h"
#include <math.h>

// Function to create a stripe pattern
t_pattern create_pattern(t_color a, t_color b)
{
    t_pattern pattern;
    pattern.a = a;
    pattern.b = b;
    return pattern;
}

// Function to get the color at a given point
t_color pattern_at(t_pattern *pattern, t_point point)
{
    if ((int)floor(point.x) % 2 == 0) {
        return pattern->a;
    } else {
        return pattern->b;
    }
}