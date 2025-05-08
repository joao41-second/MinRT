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

void	mouse_rotaitio(t_minirt *rt_struct, double *x_, double *y_)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	mlx_mouse_get_pos(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, &x, &y);
	if (y != WALL_Y / 2)
	{
		if (y < WALL_Y / 2)
			*y_ -= 0.0001 * abs(WALL_Y / 2 - y);
		if (y > WALL_Y / 2)
			*y_ += 0.0001 * abs(WALL_Y / 2 - y);
	}
	if (x != WALL_X / 2)
	{
		if (x < WALL_X / 2)
			*x_ -= 0.00001 * abs(WALL_X / 2 - x);
		if (x > WALL_X / 2)
			*x_ += 0.00001 * abs(WALL_X / 2 - x);
	}
	if (x != WALL_X / 2 || y != WALL_Y / 2)
		mlx_mouse_move(rt_struct->canva.mlx,
			rt_struct->canva.mlx_wind, WALL_X / 2, WALL_Y / 2);
}

void	mouse(t_minirt *rt_struct)
{
	t_matrix		ok;
	static double	x_ = 0;
	static double	y_ = 0;

	ok = mat_gener_identity(4);
	mouse_rotaitio(rt_struct, &x_, &y_);
	ok = lig_view_transform(rt_struct->point, create_point(0, 1, 0),
			create_vector(0, 1, 0));
	ok = mat_multip(mat_gener_rota('x', y_ * (180 / M_PI)), ok);
	ok = mat_multip(mat_gener_rota('y', x_ * (180 / M_PI)), ok);
	rt_struct->cam_m = cm_init(WALL_X, WALL_Y, M_PI / 2, ok);
}
