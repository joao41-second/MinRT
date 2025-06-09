/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/06 13:59:18 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"
#include "../minRT.h"

void update_camera_from_controls(t_minirt *rt_struct) {
	// Start from initial position
	t_point base_origin = create_point(0, 0, -50); // or your default
	t_vector base_direction = create_vector(0, 0, 1); // or your default

	// Apply translation
	t_point moved_origin = add_tuples(base_origin, rt_struct->point);

	// Apply rotations (first Y, then X for example)
	t_matrix rot_y = mat_gener_rota('y', rt_struct->rota_y);
	t_matrix rot_x = mat_gener_rota('x', rt_struct->rota_x);

	t_vector rotated_direction = base_direction;
	rotated_direction = mat_x_tuple(rotated_direction, rot_y);
	rotated_direction = mat_x_tuple(rotated_direction, rot_x);
	rt_struct->camera.origin = moved_origin;
	rt_struct->camera.direction = normalize(rotated_direction);
	camera_update_view(&rt_struct->camera);
}


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
