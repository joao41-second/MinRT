/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/18 15:51:54 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void	main_loop(t_minirt *rt_struct)
{
	int	i;
	int	a;

	i = 0;
	while (i < 100)
	{
		a = 0;
		while (a < 100)
		{
			canva_set_pixel(rt_struct, a, i, c_new(255.0, 1.0, 100.0));
			a++;
		}
		i++;
	}
	canva_update(rt_struct);
}
