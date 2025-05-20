#ifndef STRIPE_PATTERN_H
#define STRIPE_PATTERN_H

#include "../canvas/canvas_struct.h"
#include "../tuples/tuples.h"

typedef struct s_pattern {
    t_color a;
    t_color b;
} t_pattern;

t_pattern create_pattern(t_color a, t_color b);
t_color pattern_at(t_pattern *pattern, t_point point);

#endif