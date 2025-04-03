/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/03 12:57:50 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void	main_loop(t_minirt *rt_struct)
{

	static int ok = 0;

	if(ok == 0)
	{
	rt_struct->c_ray = ray_gener( create_point(0, 0, -5), create_vector(0, 0, 1));
	ft_pocket_new("canva");
	ray_canva(create_point(0, 0, -5), rt_struct);
	ft_free_all_pocket("canva");
	}
	ok++;

	canva_update(rt_struct);
};
