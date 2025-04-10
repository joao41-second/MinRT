/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:20:28 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/25 23:37:58 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double random_float(void)
{
	return ((double)rand() / RAND_MAX * 20.0 - 10.0);
}

void	test_ft_atof_random(void)
{
	char	*endptr;
	double	random_value;
	char	str_buffer[64];
	double	expected_value;

	printf(COLOR_MAGENTA "ft_atof: >>>>>Testing random float values<<<<<<\n" COLOR_RESET);
	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		random_value = random_float();
		snprintf(str_buffer, sizeof(str_buffer), "%.6f", random_value);
		
		// Parse with standard function to get expected value
		expected_value = strtod(str_buffer, NULL);
		double result = ft_atof(str_buffer, &endptr);
		printf("ft_atof(\"%s\") = %.6f, endptr = \"%s\"\n", 
			str_buffer, result, endptr);
		TEST_ASSERT_EQUAL_DOUBLE(expected_value, result);
		TEST_ASSERT_EQUAL_STRING("", endptr);
	}
}

void	test_ft_atof_edge_cases(void)
{
	char	*endptr;
	double	result;
	
	printf(COLOR_MAGENTA "ft_atof: >>>>>Testing edge cases<<<<<<\n" COLOR_RESET);
	
	result = ft_atof("123.456", &endptr);
	printf("ft_atof(\"123.456\") = %.6f, endptr = \"%s\"\n", result, endptr);
	TEST_ASSERT_EQUAL_DOUBLE(123.456, result);
	TEST_ASSERT_EQUAL_STRING("", endptr);

	result = ft_atof("-123.456", &endptr);
	printf("ft_atof(\"-123.456\") = %.6f, endptr = \"%s\"\n", result, endptr);
	TEST_ASSERT_EQUAL_DOUBLE(-123.456, result);
	TEST_ASSERT_EQUAL_STRING("", endptr);

	result = ft_atof("0.0", &endptr);
	printf("ft_atof(\"0.0\") = %.6f, endptr = \"%s\"\n", result, endptr);
	TEST_ASSERT_EQUAL_DOUBLE(0.0, result);
	TEST_ASSERT_EQUAL_STRING("", endptr);

	result = ft_atof("1.0abc", &endptr);
	printf("ft_atof(\"1.0abc\") = %.6f, endptr = \"%s\"\n", result, endptr);
	TEST_ASSERT_EQUAL_DOUBLE(1.0, result);
	TEST_ASSERT_EQUAL_STRING("abc", endptr);

	result = ft_atof("abc", &endptr);
	printf("ft_atof(\"abc\") = %.6f, endptr = \"%s\"\n", result, endptr);
	TEST_ASSERT_EQUAL_DOUBLE(0.0, result);
	TEST_ASSERT_EQUAL_STRING("abc", endptr);
}

void	test_ft_atof(void)
{
	RUN_TEST(test_ft_atof_random);
	RUN_TEST(test_ft_atof_edge_cases);
}
