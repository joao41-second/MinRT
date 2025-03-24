/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:39:09 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/18 12:53:55 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"
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

void	test_tuples(void)
{
	RUN_TEST(is_tuple_value_correct);

}