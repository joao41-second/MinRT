/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:39:09 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/22 14:17:33 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../src/tuples/quaternion.h"
#include <math.h>
#include "unity/unity.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double double_rand()
{
	return ((double)rand() / RAND_MAX * 40.0 - 20.0);
}

void	is_tuple_value_correct(void)
{
	double	rand_x, rand_y, rand_z, rand_w;
	t_tuple	tuple;

    printf(COLOR_MAGENTA "Tuple: >>>>>is_tuple_value_correct<<<<<<\n" COLOR_RESET);
	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = double_rand();
		tuple = create_tuple(rand_x, rand_y, rand_z, rand_w);
		TEST_ASSERT_EQUAL_DOUBLE(rand_x, tuple.x);
		TEST_ASSERT_EQUAL_DOUBLE(rand_y, tuple.y);
		TEST_ASSERT_EQUAL_DOUBLE(rand_z, tuple.z);
		TEST_ASSERT_EQUAL_DOUBLE(rand_w, tuple.w);
		printf("Tuple: (%.2f, %.2f, %.2f, %.2f)\n", tuple.x, tuple.y, tuple.z, tuple.w);
	}
}

void test_quat_rotate_vector_90deg_y(void)
{
    t_vector v = create_vector(1, 0, 0);
    t_quaternion q = quat_from_axis_angle(create_vector(0, 1, 0), M_PI);
    t_vector result = quat_rotate_vector(q, v);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6, 0, result.x);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6, 0, result.y);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6, -1, result.z);
}

void test_quat_rotate_vector_identity(void)
{
    t_vector v = create_vector(1, 2, 3);
    t_quaternion q = (t_quaternion){1, 0, 0, 0};
    t_vector result = quat_rotate_vector(q, v);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6, v.x, result.x);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6, v.y, result.y);
    TEST_ASSERT_DOUBLE_WITHIN(1e-6, v.z, result.z);
}

void test_quaternion(void)
{
    RUN_TEST(test_quat_rotate_vector_90deg_y);
    RUN_TEST(test_quat_rotate_vector_identity);
}

void	test_tuples(void)
{
	RUN_TEST(is_tuple_value_correct);
    RUN_TEST(test_quaternion);
}