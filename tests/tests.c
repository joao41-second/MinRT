/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:47:07 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/09 15:25:53 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.h"
#include <stdio.h>

void	setUp(void)
{
}

void	tearDown(void)
{
}

int	main(int argv,char** argc)
{
	srand(time(NULL));

	
	if(c_chek_iqual_color(c_multipl(c_new(1, 0, 0), c_new(1, 1, 1)), c_new(1, 0, 0)) == TRUE)
		printf("color ok \n");

	(void)argv;
	(void)argc;
	UNITY_BEGIN();
		// test_ligth();
		// test_view_trasfomr();
		// test_word();
		test_planes();
		test_triangle();
		test_cylinder();
	UNITY_END();
	return (0);
}
