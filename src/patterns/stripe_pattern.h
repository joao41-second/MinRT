#ifndef STRIPE_PATTERN_H
#define STRIPE_PATTERN_H

#include "canvas_struct.h"
#include "tuples.h"

typedef struct s_stripe_pattern {
    t_color a;
    t_color b;
} t_stripe_pattern;

t_stripe_pattern stripe_pattern(t_color a, t_color b);
t_color stripe_at(t_stripe_pattern pattern, t_point point);

#endif