/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:32:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/08 16:26:54 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void	handle_plane_keys(int keycode, t_object *plane, t_minirt *rt_struct)
{
	if (keycode == KEY_Z)
		rotate_plane(plane, 'z', ROTATION_SPEED, &rt_struct->camera);
	else if (keycode == KEY_X)
		rotate_plane(plane, 'x', ROTATION_SPEED, &rt_struct->camera);
	else if (keycode == KEY_Y)
		rotate_plane(plane, 'y', ROTATION_SPEED, &rt_struct->camera);
	else if (keycode == KEY_R)
		ray_reset_transform_obj(plane);
	else if (keycode == NUMPAD_3)
		ray_set_transform_obj(plane, mat_multip(plane->transform,
				mat_gener_trans(0, 1.0, 0)));
	else if (keycode == NUMPAD_6)
		ray_set_transform_obj(plane, mat_multip(plane->transform,
				mat_gener_trans(0, -1.0, 0)));
}

void	handle_camera_keys(int keycode, t_minirt *rt_struct)
{
    // Handle movement keys
    if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT
        || keycode == KEY_RIGHT || keycode == KEY_W || keycode == KEY_S)
        camera_move(rt_struct);
	
    // Handle rotation keys
    else if (keycode == NUMKEY_1 || keycode == NUMKEY_2
        || keycode == NUMKEY_3 || keycode == NUMKEY_4)
    {
        camera_rotate(rt_struct);
    }
	else
		handle_orthographic_view(rt_struct);

	//  camera_update_view(&rt_struct->camera);
	// printf("[DEBUG] Camera position: (%f, %f, %f)\n", 
	// 	rt_struct->camera.origin.x, rt_struct->camera.origin.y, rt_struct->camera.origin.z);
	// 	printf("[DEBUG] point position: (%f, %f, %f)\n", rt_struct->point.x, rt_struct->point.y, rt_struct->point.z);
}

// void	handle_camera_keys(int keycode, t_minirt *rt_struct)
// {
//     if (rt_struct->camera.mode == CAM_MODE_J)
//     {
        
//         if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT
//             || keycode == KEY_RIGHT || keycode == KEY_W || keycode == KEY_S)
//             camera_move(&rt_struct->camera, keycode, rt_struct);
//         else if (keycode == NUMKEY_1 || keycode == NUMKEY_2
//             || keycode == NUMKEY_3 || keycode == NUMKEY_4)
//             camera_rotate(&rt_struct->camera, rt_struct);
// 		else
// 		handle_orthographic_view(keycode, &rt_struct->camera);
//     }
//     else if (rt_struct->camera.mode == CAM_MODE_R)
//     {
        
//         if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT
//             || keycode == KEY_RIGHT || keycode == KEY_W || keycode == KEY_S)
//         {
            
//             if (keycode == KEY_UP)
//                 rt_struct->camera.origin.y += 0.1;
//             else if (keycode == KEY_DOWN)
//                 rt_struct->camera.origin.y -= 0.1;
//             else if (keycode == KEY_LEFT)
//                 rt_struct->camera.origin.x -= 0.1;
//             else if (keycode == KEY_RIGHT)
//                 rt_struct->camera.origin.x += 0.1;
//             else if (keycode == KEY_W)
//                 rt_struct->camera.origin.z += 0.1;
//             else if (keycode == KEY_S)
//                 rt_struct->camera.origin.z -= 0.1;
//             camera_update_view(&rt_struct->camera);
//         }
//         else if (keycode == NUMKEY_1 || keycode == NUMKEY_2
//             || keycode == NUMKEY_3 || keycode == NUMKEY_4)
//         {
            
//             if (keycode == NUMKEY_1)
//                 rt_struct->rota_x += ROTATION_SPEED;
//             else if (keycode == NUMKEY_2)
//                 rt_struct->rota_x -= ROTATION_SPEED;
//             else if (keycode == NUMKEY_3)
//                 rt_struct->rota_y += ROTATION_SPEED;
//             else if (keycode == NUMKEY_4)
//                 rt_struct->rota_y -= ROTATION_SPEED;
//             camera_rotate(&rt_struct->camera, rt_struct);
//         }
// 		else
// 			handle_orthographic_view(keycode, &rt_struct->camera);
//     }
// }



void	handle_light_keys(int keycode, t_minirt *rt_struct)
{
	if (keycode == KEY_O)
		rt_struct->luz.point.x += 1;
	else if (keycode == KEY_P)
		rt_struct->luz.point.x -= 1;
	else if (keycode == KEY_I)
		rt_struct->luz.point.y += 1;
	else if (keycode == KEY_K)
		rt_struct->luz.point.y -= 1;
	else if (keycode == KEY_L)
		rt_struct->luz.point.z += 1;
	else if (keycode == KEY_J)
		rt_struct->luz.point.z -= 1;
	else if (keycode == KEY_SPACE)
	{
		rt_struct->luz.point.x = 0;
		rt_struct->luz.point.y = 0;
		rt_struct->luz.point.z = 0;
	}
}

void	handle_misc_keys(int keycode, t_minirt *rt_struct)
{
	t_camera_mode	new_mode;

	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind);
		exit(0);
	}
	else if (keycode == KEY_M)
	{
		if (rt_struct->camera.mode == CAM_MODE_R)
			new_mode = CAM_MODE_J;
		else
			new_mode = CAM_MODE_R;
		unified_camera_set_mode(&rt_struct->camera, new_mode);
	}
	else if (keycode == KEY_TAB)
	{
		rt_struct->menu = !rt_struct->menu;
		
	}
	else if (keycode == NUMKEY_9)
		rt_struct->needs_render++;
	else if (keycode == NUMKEY_8)
		rt_struct->needs_render--;
	if (rt_struct->needs_render <= 1)
		rt_struct->needs_render = 1;
}

void	key_loop(int keycode, t_minirt *rt_struct)
{
	t_list_		*current;
	t_object	*plane;
	t_object	*obj;

	rt_struct->clicked = keycode;
	plane = NULL;
	current = rt_struct->word;
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
	printf("[DEBUG] Key pressed: %d\n", rt_struct->clicked);
	if (plane)
		handle_plane_keys(keycode, plane, rt_struct);
	handle_camera_keys(keycode, rt_struct);
	handle_light_keys(keycode, rt_struct);
	handle_misc_keys(keycode, rt_struct);
	// camera_update_view(&rt_struct->camera);
	canva_update(rt_struct);
}
