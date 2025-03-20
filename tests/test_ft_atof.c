/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:20:28 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/20 14:13:03 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "tests.h"

void	test_ft_atof(void)
{
	char	*endptr;

	TEST_ASSERT_EQUAL_DOUBLE(123.456, ft_atof("123.456", &endptr));
	TEST_ASSERT_EQUAL_STRING("", endptr);

	TEST_ASSERT_EQUAL_DOUBLE(-123.456, ft_atof("-123.456", &endptr));
	TEST_ASSERT_EQUAL_STRING("", endptr);

	TEST_ASSERT_EQUAL_DOUBLE(0.0, ft_atof("0.0", &endptr));
	TEST_ASSERT_EQUAL_STRING("", endptr);

	TEST_ASSERT_EQUAL_DOUBLE(1.0, ft_atof("1.0abc", &endptr));
	TEST_ASSERT_EQUAL_STRING("abc", endptr);

	TEST_ASSERT_EQUAL_DOUBLE(0.0, ft_atof("abc", &endptr));
	TEST_ASSERT_EQUAL_STRING("abc", endptr);
}
