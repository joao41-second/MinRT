/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/10 13:29:18 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"
#include "../minRT.h"

void	loop(t_minirt *rt_struct)
{
	char	*str;
	
//	mouse(rt_struct);
	
	mat_set_view_transform(&rt_struct->cam_m.tranform_matrix, create_point(0, 1.5,-5), 
			create_point(0, 0, 0), create_vector(0, 1, 0));

	mat_set_multip(&rt_struct->cam_m.tranform_matrix,mat_gener_rota('y', rt_struct->rota_x),mat_cp(rt_struct->cam_m.tranform_matrix));

	mat_set_multip(&rt_struct->cam_m.tranform_matrix,mat_gener_rota('x', rt_struct->rota_y),mat_cp(rt_struct->cam_m.tranform_matrix));
	mat_set_multip(&rt_struct->cam_m.tranform_matrix,mat_cp(rt_struct->cam_m.tranform_matrix),
			mat_gener_trans(rt_struct->point.x, rt_struct->point.y, rt_struct->point.z));

	//mat_set_multip(&rt_struct->cam_m.tranform_matrix,mat_gener_rota('z', 1.7),mat_cp(rt_struct->cam_m.tranform_matrix));



	cm_update(&rt_struct->cam_m);
	cm_windo_put(rt_struct, WALL_X, WALL_Y,5);

	canva_update(rt_struct);
	asprintf(&str, "cord: %f %f %f  dir: %f %f %f",
		rt_struct->cam.origin.x, rt_struct->cam.origin.y,
		rt_struct->cam.origin.z, rt_struct->cam.direction.x,
		rt_struct->cam.direction.y, rt_struct->cam.direction.z);
	mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind,
		10, 10, create_trgb(1, 255, 255, 2), str);
	asprintf(&str, "cord: %f %f %f ", rt_struct->luz.point.x,
		rt_struct->luz.point.y, rt_struct->luz.point.z);
	mlx_string_put(rt_struct->canva.mlx,
		rt_struct->canva.mlx_wind,
		20, 20, create_trgb(1, 255, 255, 2), str);
}
