/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:32:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/08 14:06:24 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

// void	key_loop(int key, t_minirt *rt_struct)
// {
// 	(void)key;
// 	(void)rt_struct;
// }
/**
 * Implementation of standard orthographic views
 * These functions can be called when specific keys are pressed
 */
void set_top_view(t_camera *cam)
{
    cam->origin = create_point(0, 10, 0);
    cam->direction = create_vector(0, -1, 0);
    camera_update_view(cam);
}
void set_front_view(t_camera *cam)
{
    cam->origin = create_point(0, 1, -10);
    cam->direction = create_vector(0, 0, 1);
    camera_update_view(cam);
}
void set_right_view(t_camera *cam)
{
    cam->origin = create_point(10, 1, 0);
    cam->direction = create_vector(-1, 0, 0);
    camera_update_view(cam);
}
void set_left_view(t_camera *cam)
{
    cam->origin = create_point(-10, 1, 0);
    cam->direction = create_vector(1, 0, 0);
    camera_update_view(cam);
}
void set_back_view(t_camera *cam)
{
    cam->origin = create_point(0, 1, 10);
    cam->direction = create_vector(0, 0, -1);
    camera_update_view(cam);
}
void set_bottom_view(t_camera *cam)
{
    cam->origin = create_point(0, -10, 0);
    cam->direction = create_vector(0, 1, 0);
    camera_update_view(cam);
}

void rotate_plane(t_object *plane, char axis, double angle, t_camera *cam)
{
    if (!plane || plane->type != OBJ_PLANE)
        return;
    t_matrix rotation_matrix;
    if (axis == 'x')
        rotation_matrix = mat_gener_rota('x', angle);
    else if (axis == 'y')
        rotation_matrix = mat_gener_rota('y', angle);
    else if (axis == 'z')
        rotation_matrix = mat_gener_rota('z', angle);
    else
        return;
    t_matrix new_transform = mat_multip(plane->transform, rotation_matrix);
    ray_set_transform_obj(plane, new_transform);
    camera_update_view(cam);

}

void ray_reset_transform_obj(t_object *obj)
{
    if (obj->type == OBJ_PLANE)
    {
        t_object *plane = obj;

        // Reset transformation matrices
        mat_free(&plane->transform);
        mat_free(&plane->inv_transform);
        mat_free(&plane->inv_transpose);

        plane->transform = mat_gener_identity(4);
        plane->inv_transform = mat_gener_identity(4);
        plane->inv_transpose = mat_gener_identity(4);

        // Reset the normal vector to the base normal
        plane->u_data.plane.normal = create_vector(0, 1, 0);

        printf("Plane transform reset:\n");
        mat_print(plane->transform);
        printf("Reset plane normal: (%f, %f, %f)\n", plane->u_data.plane.normal.x, plane->u_data.plane.normal.y, plane->u_data.plane.normal.z);
    }
}
void key_loop(int keycode, t_minirt *rt_struct)
{
    // t_minirt *rt_struct = (t_minirt *)param;
    t_list_  *current = rt_struct->word;

    t_object *plane = NULL;
    while (current)
    {
        t_object *obj = (t_object *)current->content;
        if (obj->type == OBJ_PLANE)
        {
            plane = obj;
            // print_plane(&obj->u_data.plane);
            break;
        }
        current = current->next;
    }

    if (plane)
    {
        if (keycode == KEY_Z) {
            rotate_plane(plane, 'z', ROTATION_SPEED, &rt_struct->scene.world.camera);
        } else if (keycode == KEY_X) { // Rotate plane around X-axis
            rotate_plane(plane, 'x', ROTATION_SPEED, &rt_struct->scene.world.camera);
        } else if (keycode == KEY_Y) { // Rotate plane around Y-axis
            rotate_plane(plane, 'y', ROTATION_SPEED, &rt_struct->scene.world.camera);}
        else if (keycode == KEY_MINUS){
            plane->u_data.plane.center.y += 10;
            
        }
        else if (keycode == KEY_R) {
            ray_reset_transform_obj(plane);
        }
        canva_update(rt_struct);
    }

    if (keycode == KEY_UP || keycode == KEY_DOWN || 
        keycode == KEY_LEFT || keycode == KEY_RIGHT || 
        keycode == KEY_W || keycode == KEY_S) {
        camera_move(&rt_struct->scene.world.camera, keycode);
    }
    else if (keycode == NUMKEY_1) {
        camera_rotate(&rt_struct->scene.world.camera, -ROTATION_SPEED, 0);
    }
    else if (keycode == NUMKEY_2) { // Rotate camera right (yaw)
        camera_rotate(&rt_struct->scene.world.camera, ROTATION_SPEED, 0);
    }
    else if (keycode == NUMKEY_3) { // Rotate camera up (pitch)
        camera_rotate(&rt_struct->scene.world.camera, 0, -ROTATION_SPEED);
    }
    else if (keycode == NUMKEY_4) { // Rotate camera down (pitch)
        camera_rotate(&rt_struct->scene.world.camera, 0, ROTATION_SPEED);
    }
    else if (keycode == NUMKEY_5) { // Rotate camera counterclockwise (roll)
        camera_rotate(&rt_struct->scene.world.camera, 0, 0); // Implement roll logic if needed
    }
    else if (keycode == NUMKEY_6) { // Rotate camera clockwise (roll)
        camera_rotate(&rt_struct->scene.world.camera, 0, 0); // Implement roll logic if needed
    }
    else if (keycode == NUMPAD_1) {  
        set_front_view(&rt_struct->scene.world.camera);
    }
    else if (keycode == NUMPAD_4) {  
        set_right_view(&rt_struct->scene.world.camera);
    }
    else if (keycode == NUMPAD_7) {  
        set_top_view(&rt_struct->scene.world.camera);
    }
    else if (keycode == NUMPAD_2) {  
        set_back_view(&rt_struct->scene.world.camera);
    }
    else if (keycode == NUMPAD_5) {  
        set_left_view(&rt_struct->scene.world.camera);
    }
    else if (keycode == NUMPAD_8) {  
        set_bottom_view(&rt_struct->scene.world.camera);
    }
	else if(keycode == KEY_O)
	{
		rt_struct->luz.point.x +=1;
	}

	else if(keycode == KEY_P)
	{
		rt_struct->luz.point.x -=1;
	}

	else if(keycode == KEY_I)
	{
		rt_struct->luz.point.y +=1;
	}

	else if(keycode == KEY_K)
	{
		rt_struct->luz.point.y -=1;
	}
	else if(keycode == KEY_L)
	{
		rt_struct->luz.point.z +=1;
	}
	else if(keycode == KEY_J)
	{
		rt_struct->luz.point.z -=1;
	}
	else if(keycode == KEY_SPACE)
	{
		rt_struct->luz.point.x = 0;
		rt_struct->luz.point.y = 0;
		rt_struct->luz.point.z = 0;
	}
    else if (keycode == KEY_ESC) {
        mlx_destroy_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind);
        exit(0);
    }
    canva_update(rt_struct);
    // return (1);
}