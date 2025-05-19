#include "unity.h"
#include "stripe_pattern.h"
#include "tuples.h"

void test_stripe_pattern_creation(void) {
    t_color white = {1, 1, 1};
    t_color black = {0, 0, 0};
    t_stripe_pattern pattern = stripe_pattern(white, black);

    TEST_ASSERT_EQUAL_DOUBLE(1, pattern.a.red);
    TEST_ASSERT_EQUAL_DOUBLE(0, pattern.b.red);
}

void test_stripe_at_constant_y(void) {
    t_color white = {1, 1, 1};
    t_color black = {0, 0, 0};
    t_stripe_pattern pattern = stripe_pattern(white, black);

    t_point point = {0, 0, 0};
    TEST_ASSERT_EQUAL_DOUBLE(1, stripe_at(pattern, point).red);

    point.y = 1;
    TEST_ASSERT_EQUAL_DOUBLE(1, stripe_at(pattern, point).red);
}

void test_stripe_at_alternates_x(void) {
    t_color white = {1, 1, 1};
    t_color black = {0, 0, 0};
    t_stripe_pattern pattern = stripe_pattern(white, black);

    t_point point = {0, 0, 0};
    TEST_ASSERT_EQUAL_DOUBLE(1, stripe_at(pattern, point).red);

    point.x = 1;
    TEST_ASSERT_EQUAL_DOUBLE(0, stripe_at(pattern, point).red);

    point.x = -1;
    TEST_ASSERT_EQUAL_DOUBLE(0, stripe_at(pattern, point).red);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_stripe_pattern_creation);
    RUN_TEST(test_stripe_at_constant_y);
    RUN_TEST(test_stripe_at_alternates_x);
    return UNITY_END();
}