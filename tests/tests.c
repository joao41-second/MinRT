/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:47:07 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/29 16:23:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

int	main(int argv,char** argc)
{
	srand(time(NULL));
	(void)argv;
	(void)argc;
	UNITY_BEGIN();
		test_ligth();
		test_view_trasfomr();
		test_word();
	UNITY_END();
	return (0);
}
