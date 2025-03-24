/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:47:07 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/20 13:47:55 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "tests.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

int	main(void)
{
	srand(time(NULL));
	UNITY_BEGIN();
	test_tuples();
	// test_ft_atof();
	UNITY_END();
	return (0);
}
