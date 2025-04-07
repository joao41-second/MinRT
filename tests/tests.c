/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:47:07 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/07 09:48:30 by jperpct          ###   ########.fr       */
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
	UNITY_BEGIN();
	if(ft_strncmp(argc[1],"light",ft_strlen("light")+5) == 0)
	{
		test_ligth();
	}
	else
	{	
	test_tuples();
	test_ft_atof();
	}
	UNITY_END();
	return (0);
}
