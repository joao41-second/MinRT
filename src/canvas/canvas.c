/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:39:58 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/18 14:23:06 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "../minRT.h"
#include <stdio.h>

int	canva_loop(t_minirt *rt_struct)
{
	loop(rt_struct);
	return (1);
}

int	canva_loop_key(int keycode, void *param)
{
	t_minirt	*rt_struct;

	rt_struct = (t_minirt *)param;
	key_loop(keycode, rt_struct);
	return (1);
}

void	canva_inicializ(t_minirt *rt_struct, int x, int y, t_color base)
{
	(void)base;
	if (!rt_struct)
		return ;
	ft_memset(&rt_struct->canva, 0, sizeof(t_canva));
	rt_struct->canva.mlx = ft_add_memory(mlx_init(), NULL);
	rt_struct->canva.mlx_wind = mlx_new_window(rt_struct->canva.mlx,
			x, y, "new minRT");
	rt_struct->canva.canva.img = mlx_new_image(rt_struct->canva.mlx, x, y);
	rt_struct->canva.canva.addr = mlx_get_data_addr(rt_struct->canva.canva.img,
			&rt_struct->canva.canva.bits_per_pixel,
			&rt_struct->canva.canva.line_length,
			&rt_struct->canva.canva.endian);
	mlx_key_hook(rt_struct->canva.mlx_wind, canva_loop_key, rt_struct);
	mlx_loop_hook(rt_struct->canva.mlx, canva_loop, rt_struct);
	mlx_hook(rt_struct->canva.mlx_wind,
		17, 01, &mlx_loop_end, rt_struct->canva.mlx);
	mlx_loop(rt_struct->canva.mlx);
	mlx_destroy_image(rt_struct->canva.mlx, rt_struct->canva.canva.img);
	mlx_destroy_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind);
	mlx_destroy_display(rt_struct->canva.mlx);
	ft_free_all();
}
