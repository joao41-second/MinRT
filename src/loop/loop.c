/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 09:48:05 by rerodrig         ###   ########.fr       */
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
	cm_update(&rt_struct->camera);
	cm_windo_put(rt_struct, WALL_X, WALL_Y, rt_struct->needs_render);
	canva_update(rt_struct);
	draw_axis_navigator(rt_struct);
	draw_orientation_cube(rt_struct);
	draw_cube_labels(rt_struct);
	ft_menu(rt_struct);
}
