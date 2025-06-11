/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/09 14:02:27 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"
#include "../minRT.h"

void	loop(t_minirt *rt_struct)
{
	char	*str;

	if (rt_struct->camera.mode == CAM_MODE_J)
	{
		mat_set_view_transform(&rt_struct->camera.tranform_matrix,
			create_point(0, 0, 1),
			create_point(0, 0, 0),
			create_vector(0, 1, 0));
		cm_update(&rt_struct->camera);
	}
	else
		camera_update_view(&rt_struct->camera);
	mat_set_multip(&rt_struct->camera.tranform_matrix,
		mat_gener_rota('x', rt_struct->rota_x),
		mat_cp(rt_struct->camera.tranform_matrix));
	mat_set_multip(&rt_struct->camera.tranform_matrix,
		mat_gener_rota('y', rt_struct->rota_y),
		mat_cp(rt_struct->camera.tranform_matrix));
	mat_set_multip(&rt_struct->camera.tranform_matrix,
		mat_cp(rt_struct->camera.tranform_matrix),
		mat_gener_trans(rt_struct->point.x, rt_struct->point.y,
			rt_struct->point.z));
	cm_windo_put(rt_struct, WALL_X, WALL_Y, rt_struct->needs_render);
	canva_update(rt_struct);
}
