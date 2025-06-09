/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:32:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/05 13:28:38 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void	handle_plane_keys(int keycode, t_object *plane, t_minirt *rt_struct)
{
	if (rt_struct->clicked == KEY_Z)
		rotate_plane(plane, 'z', ROTATION_SPEED, &rt_struct->camera);
	else if (rt_struct->clicked == KEY_X)
		rotate_plane(plane, 'x', ROTATION_SPEED, &rt_struct->camera);
	else if (rt_struct->clicked == KEY_Y)
		rotate_plane(plane, 'y', ROTATION_SPEED, &rt_struct->camera);
	else if (rt_struct->clicked == KEY_R)
		ray_reset_transform_obj(plane);
	else if (rt_struct->clicked == NUMPAD_3)
		ray_set_transform_obj(plane, mat_multip(plane->transform,
				mat_gener_trans(0, 1.0, 0)));
	else if (rt_struct->clicked == NUMPAD_6)
		ray_set_transform_obj(plane, mat_multip(plane->transform,
				mat_gener_trans(0, -1.0, 0)));
}

void	handle_camera_keys(int keycode, t_minirt *rt_struct)
{
	if (rt_struct->clicked == KEY_UP || rt_struct->clicked == KEY_DOWN || \
		rt_struct->clicked == KEY_LEFT || rt_struct->clicked == KEY_RIGHT || \
		rt_struct->clicked == KEY_W || rt_struct->clicked == KEY_S)
		camera_move(&rt_struct->camera, keycode);
	else if (rt_struct->clicked == NUMKEY_1)
		camera_rotate(&rt_struct->camera, -ROTATION_SPEED, 0);
	else if (rt_struct->clicked == NUMKEY_2)
		camera_rotate(&rt_struct->camera, ROTATION_SPEED, 0);
	else if (rt_struct->clicked == NUMKEY_3)
		camera_rotate(&rt_struct->camera, 0, -ROTATION_SPEED);
	else if (rt_struct->clicked == NUMKEY_4)
		camera_rotate(&rt_struct->camera, 0, ROTATION_SPEED);
	else
		handle_orthographic_view(rt_struct);
}

void	handle_light_keys(t_minirt *rt_struct)
{
	if (rt_struct->clicked == KEY_O)
		rt_struct->luz.point.x += 1;
	else if (rt_struct->clicked == KEY_P)
		rt_struct->luz.point.x -= 1;
	else if (rt_struct->clicked == KEY_I)
		rt_struct->luz.point.y += 1;
	else if (rt_struct->clicked == KEY_K)
		rt_struct->luz.point.y -= 1;
	else if (rt_struct->clicked == KEY_L)
		rt_struct->luz.point.z += 1;
	else if (rt_struct->clicked == KEY_J)
		rt_struct->luz.point.z -= 1;
	else if (rt_struct->clicked == KEY_SPACE)
	{
		rt_struct->luz.point.x = 0;
		rt_struct->luz.point.y = 0;
		rt_struct->luz.point.z = 0;
	}
}

void	handle_misc_keys(t_minirt *rt_struct)
{
	t_camera_mode	new_mode;

	if (rt_struct->clicked == KEY_ESC)
	{
		mlx_destroy_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind);
		exit(0);
	}
	else if (rt_struct->clicked == KEY_M)
	{
		if (rt_struct->camera.mode == CAM_MODE_R)
			new_mode = CAM_MODE_J;
		else
			new_mode = CAM_MODE_R;
		unified_camera_set_mode(&rt_struct->camera, new_mode);
	}
	else if (rt_struct->clicked == KEY_TAB)
		rt_struct->menu = !rt_struct->menu;
	else if (rt_struct->clicked == NUMKEY_9)
		rt_struct->needs_render++;
	else if (rt_struct->clicked == NUMKEY_8)
		rt_struct->needs_render--;
	if (rt_struct->needs_render <= 1)
		rt_struct->needs_render = 1;
}

void	key_loop(int keycode, t_minirt *rt_struct)
{
	t_list_		*current;
	t_object	*plane;
	t_object	*obj;

	plane = NULL;
	current = rt_struct->word;
	rt_struct->clicked = keycode;
	while (current)
	{
		obj = (t_object *)current->content;
		if (obj->type == OBJ_PLANE)
		{
			plane = obj;
			break ;
		}
		current = current->next;
	}
	if (plane)
		handle_plane_keys(keycode, plane, rt_struct);
	handle_camera_keys(keycode, rt_struct);
	handle_light_keys(rt_struct);
	handle_misc_keys(rt_struct);
}
