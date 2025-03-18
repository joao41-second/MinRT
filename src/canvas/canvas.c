/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:04:04 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/18 10:35:12 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include <stdio.h>

int canva_loop(t_minirt* rt_struct)
{
	printf("ok\n");
	return 1;
}


void canva_inicializ(t_minirt *rt_struct,int x, int y, t_color base)
{
	ft_pocket_new("canva");
	rt_struct->canva.mlx = ft_add_memory(mlx_init(), NULL);
	rt_struct->canva.mlx_wind  = ft_add_memory(mlx_new_window(rt_struct->canva.mlx, x, y, "new minRT"), NULL);
	rt_struct->canva.canva = ft_add_memory(mlx_new_image(rt_struct->canva.mlx, x, y), NULL);
	//mlx_loop_hook(rt_struct->canva.mlx_wind, canva_loop, rt_struct);
	mlx_loop(rt_struct->canva.mlx);
	ft_pocket_set("main");
}


