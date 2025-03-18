/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:47:07 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/18 12:47:55 by rerodrig         ###   ########.fr       */
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
	UNITY_END();
	return (0);
}
