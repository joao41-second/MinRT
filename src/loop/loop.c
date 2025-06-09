/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/08 16:32:09 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"
#include "../minRT.h"
// #include "../canvas/menu/menu.h"

void update_camera_from_controls(t_minirt *rt_struct) {
	// Start from initial position
	t_point base_origin = rt_struct->camera.origin; // or your default
	t_vector base_direction = rt_struct->camera.direction; // or your default

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
	update_camera_from_controls(rt_struct);
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
	rt_struct->cam = unified_camera_generate_ray(&rt_struct->camera,
		(double)WALL_X / 2, (double)WALL_Y / 2);
	// cm_update(&rt_struct->camera);
	cm_windo_put(rt_struct, WALL_X, WALL_Y, rt_struct->needs_render);
	canva_update(rt_struct);
	// printf("[DEBUG] Camera position: (%f, %f, %f)\n", rt_struct->camera.origin.x, rt_struct->camera.origin.y, rt_struct->camera.origin.z);
	// printf("[DEBUG] point position: (%f, %f, %f)\n", rt_struct->point.x, rt_struct->point.y, rt_struct->point.z);

		

	// draw_axis_navigator(rt_struct);
	// draw_orientation_cube(rt_struct);
	// draw_cube_labels(rt_struct);
	// draw_camera_info(rt_struct);

}
