#include "stripe_pattern.h"
#include <math.h>

// Function to create a stripe pattern
t_stripe_pattern stripe_pattern(t_color a, t_color b) {
    t_stripe_pattern pattern;
    pattern.a = a;
    pattern.b = b;
    return pattern;
}

// Function to get the color at a given point
t_color stripe_at(t_stripe_pattern pattern, t_point point) {
    if ((int)floor(point.x) % 2 == 0) {
        return pattern.a;
    } else {
        return pattern.b;
    }
}