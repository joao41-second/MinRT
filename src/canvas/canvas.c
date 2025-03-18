/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:04:04 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/18 14:00:43 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

int canva_loop(t_minirt* rt_struct)
{
	return 1;
}

int canva_loop_key(int keycode,void *param)
{
	t_minirt *rt_struct;

	rt_struct = (t_minirt*) param;
	printf("the key is %d \n",keycode);


	return 1;
}

int canva_loop_mouse(int button,int x,int y,void *param)
{
	t_minirt *rt_struct;
	rt_struct = (t_minirt*) param;
	return 1;
}

void canva_inicializ(t_minirt *rt_struct,int x, int y, t_color base)
{
	ft_pocket_new("canva");
	rt_struct->canva.mlx =ft_add_memory(mlx_init(),NULL);
	rt_struct->canva.mlx_wind  = mlx_new_window(rt_struct->canva.mlx, x, y, "new minRT");
//	rt_struct->canva.canva = ft_add_memory(mlx_new_image(rt_struct->canva.mlx, x, y), NULL);
	ft_pocket_set("main");
	mlx_key_hook(rt_struct->canva.mlx_wind, canva_loop_key, rt_struct);
	mlx_mouse_hook(rt_struct->canva.mlx_wind, canva_loop_mouse, rt_struct);
	mlx_loop_hook(rt_struct->canva.mlx, canva_loop, rt_struct);
	mlx_hook(rt_struct->canva.mlx_wind, 17, 01, &mlx_loop_end,rt_struct->canva.mlx);
	mlx_loop(rt_struct->canva.mlx);

	mlx_destroy_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind);
	mlx_destroy_display(rt_struct->canva.mlx);
	ft_free_all();
}


