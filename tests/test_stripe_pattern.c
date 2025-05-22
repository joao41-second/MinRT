#include <stdio.h>
#include <assert.h>
#include "../src/patterns/pattern.h"
#include "../src/tuples/tuples.h"
#include "tests.h"

void	test_pattern_creation(void)
{
    t_color white = {1, 1, 1};
    t_color black = {0, 0, 0};
    t_pattern pattern = create_pattern(white, black);

    assert(pattern.a.red == 1);
    assert(pattern.b.red == 0);
    printf("Stripe pattern creation test passed.\n");
}

void	test_pattern_at(void)
{
    t_color white = {1, 1, 1};
    t_color black = {0, 0, 0};
    t_pattern pattern = create_pattern(white, black);

    t_point point = {0, 0, 0};
    assert(pattern_at(pattern, point).red == 1);

    point.x = 1;
    assert(pattern_at(pattern, point).red == 0);

    point.x = 2;
    assert(pattern_at(pattern, point).red == 1);
    printf("Stripe pattern pattern_at test passed.\n");
}

void	test_patterns(void)
{
	RUN_TEST(test_pattern_creation);
    RUN_TEST(test_pattern_at);

}