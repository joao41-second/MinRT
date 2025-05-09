/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maose.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:13:28 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 15:27:22 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minRT.h"

void	mouse_rotaitio(t_minirt *rt_struct)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	mlx_mouse_get_pos(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, &x, &y);
	if (y != WALL_Y / 2)
	{
		if (y < WALL_Y / 2)
			rt_struct->rota_y -= 0.0001 * abs(WALL_Y / 2 - y);
		if (y > WALL_Y / 2)
			rt_struct->rota_y += 0.0001 * abs(WALL_Y / 2 - y);
	}
	if (x != WALL_X / 2)
	{
		if (x < WALL_X / 2)
			rt_struct->rota_x -= 0.0001 * abs(WALL_X / 2 - x);
		if (x > WALL_X / 2)
			rt_struct->rota_x += 0.0001 * abs(WALL_X / 2 - x);
	}
	if (x != WALL_X / 2 || y != WALL_Y / 2)
		mlx_mouse_move(rt_struct->canva.mlx,
			rt_struct->canva.mlx_wind, WALL_X / 2, WALL_Y / 2);
}

void	mouse(t_minirt *rt_struct)
{

	mouse_rotaitio(rt_struct);
}
