/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:13:28 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/30 15:20:49 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../minRT.h"
#include <stdio.h>


void mouse(t_minirt *rt_struct)
{
//	static t_point p1;
//	static t_point p2;
//	static int x_ ;
//	static int y_;
	int x;
	int y;
	mlx_mouse_get_pos(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, &x, &y);
	t_ray rat =  cm_ray_for_pixel(rt_struct->cam_m, x, y);
	t_matrix  ok;

	ok = lig_view_transform(rt_struct->point,scalar_mult_tuples(rat.direction, 1), create_vector(0, 1,0));

        rt_struct->cam_m = cm_init( WALL_X ,WALL_Y , M_PI/2, ok);

	

}
