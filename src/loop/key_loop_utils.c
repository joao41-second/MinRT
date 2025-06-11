/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:32:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/05 13:29:28 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void	rotate_plane(t_object *plane, char axis, double angle, t_camera_ms *cam)
{
	t_matrix	rotation_matrix;
	t_matrix	new_transform;

	if (!plane || plane->type != OBJ_PLANE)
		return ;
	if (axis == 'x')
		rotation_matrix = mat_gener_rota('x', angle);
	else if (axis == 'y')
		rotation_matrix = mat_gener_rota('y', angle);
	else if (axis == 'z')
		rotation_matrix = mat_gener_rota('z', angle);
	else
		return ;
	new_transform = mat_multip(plane->transform, rotation_matrix);
	ray_set_transform_obj(plane, new_transform);
	camera_update_view(cam);
}

void	ray_reset_transform_obj(t_object *obj)
{
	if (obj->type == OBJ_PLANE)
	{
		mat_free(&obj->transform);
		mat_free(&obj->inv_transform);
		mat_free(&obj->inv_transpose);
		obj->transform = mat_gener_identity(4);
		obj->inv_transform = mat_gener_identity(4);
		obj->inv_transpose = mat_gener_identity(4);
		obj->u_data.plane.normal = create_vector(0, 1, 0);
		mat_print(obj->transform);
	}
}

void	rotate_scene(t_minirt *rt_struct, char axis, double angle)
{
	t_list_		*current;
	t_matrix	rotation_matrix;
	t_matrix	new_transform;
	t_object	*obj;

	current = rt_struct->word;
	rotation_matrix = mat_gener_rota(axis, angle);
	while (current)
	{
		obj = (t_object *)current->content;
		new_transform = mat_multip(obj->transform, rotation_matrix);
		ray_set_transform_obj(obj, new_transform);
		current = current->next;
	}
	canva_update(rt_struct);
}

void	set_ortho(t_camera_ms *cam, t_point origin,
		t_vector direction)
{
	cam->origin = origin;
	cam->direction = direction;
}

void	handle_orthographic_view(t_minirt *rt_struct)
{
	if (rt_struct->clicked == NUMPAD_1)
		set_ortho(&rt_struct->camera, create_point(0, 1, -10), \
		create_vector(0, 0, 1));
	else if (rt_struct->clicked == NUMPAD_4)
		set_ortho(&rt_struct->camera, create_point(10, 1, 0), \
		create_vector(-1, 0, 0));
	else if (rt_struct->clicked == NUMPAD_7)
		set_ortho(&rt_struct->camera, create_point(0, 10, 0), \
		create_vector(0, -1, 0));
	else if (rt_struct->clicked == NUMPAD_2)
		set_ortho(&rt_struct->camera, create_point(0, 1, 10), \
		create_vector(0, 0, -1));
	else if (rt_struct->clicked == NUMPAD_5)
		set_ortho(&rt_struct->camera, create_point(-10, 1, 0), \
		create_vector(1, 0, 0));
	else if (rt_struct->clicked == NUMPAD_8)
		set_ortho(&rt_struct->camera, create_point(0, -10, 0), \
		create_vector(0, 1, 0));
	else
		return ;
}
