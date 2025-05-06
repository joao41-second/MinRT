/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:32:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/06 12:48:21 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../minRT.h"
#include <stdio.h>

// void key_loop(int key, t_minirt *rt_structj)
// {
// //	t_matrix ok ;

// //	ok = mat_gener_identity(0);


// //	t_point point = create_point(0,1,-5);
// 	static	double x = 0.054;
// 	static	double z = -0.8;
// 	static	double y;
	


// 	if(key == KEY_W)
// 	{
// 		x+=0.1;
// 	}

// 	if(key == KEY_S)
// 	{
// 		x-=0.1;
// 	}

// 	if(key == KEY_D)
// 	{
// 	}

// 	if(key == KEY_A)
// 	{
// 	}

// 	t_matrix ok ;


// 	ok = mat_gener_identity(4);

// 	rt_structj->point = create_point(0,0,-2);

// 	ok = lig_view_transform(rt_structj->point, create_point(0,0,0), create_vector(0, 1,0));

// 	ok = mat_multip( ok,mat_gener_rota('z',x));

//         rt_structj->cam_m = cm_init( WALL_X ,WALL_Y , M_PI/2, ok);
// 	if(is_equal_double(x, 6.5))
// 		x = 0;
// 	printf("rota %f\n",x);




// }



/**
 * Implementation of standard orthographic views
 * These functions can be called when specific keys are pressed
 */
void set_top_view(t_camera *cam)
{
    cam->origin = create_point(0, 100, 0);
    cam->direction = create_vector(0, -1, 0);
    camera_update_view(cam);
}
void set_front_view(t_camera *cam)
{
    cam->origin = create_point(0, 0, -100);
    cam->direction = create_vector(0, 0, 1);
    camera_update_view(cam);
}
void set_right_view(t_camera *cam)
{
    cam->origin = create_point(100, 0, 0);
    cam->direction = create_vector(-1, 0, 0);
    camera_update_view(cam);
}
void set_left_view(t_camera *cam)
{
    cam->origin = create_point(-100, 0, 0);
    cam->direction = create_vector(1, 0, 0);
    camera_update_view(cam);
}
void set_back_view(t_camera *cam)
{
    cam->origin = create_point(0, 0, 100);
    cam->direction = create_vector(0, 0, -1);
    camera_update_view(cam);
}
void set_bottom_view(t_camera *cam)
{
    cam->origin = create_point(0, -100, 0);
    cam->direction = create_vector(0, 1, 0);
    camera_update_view(cam);
}
/**
 * Extended key handler to support standard views
 * Add these cases to your existing canva_loop_key function
 */
void rotate_plane(t_object *plane, char axis, double angle, t_camera *cam)
{
    // Ensure the plane is valid
    if (!plane || plane->type != OBJ_PLANE)
        return;
    t_matrix rotation_matrix;

    // Generate the rotation matrix based on the axis
    if (axis == 'x')
        rotation_matrix = mat_gener_rota('x', angle);
    else if (axis == 'y')
        rotation_matrix = mat_gener_rota('y', angle);
    else if (axis == 'z')
        rotation_matrix = mat_gener_rota('z', angle);
    else
        return;

    // Apply the rotation to the plane's existing transformation matrix
    t_matrix new_transform = mat_multip(plane->u_data.plane.transform, rotation_matrix);
    ray_set_transform_obj(plane, new_transform);
    camera_update_view(cam);
    // Free the temporary matrices
    mat_free(&rotation_matrix);
    mat_free(&new_transform);
}
void print_plane(t_plane *plane)
{
    printf("Plane Details:\n");
    printf("Center: (%f, %f, %f)\n", plane->center.x, plane->center.y, plane->center.z);
    printf("Normal: (%f, %f, %f)\n", plane->normal.x, plane->normal.y, plane->normal.z);
    printf("Base Normal: (%f, %f, %f)\n", plane->base_normal.x, plane->base_normal.y, plane->base_normal.z);
    printf("Color: (%f, %f, %f)\n", plane->color.red, plane->color.green, plane->color.blue);
    printf("Material Color: (%f, %f, %f)\n", plane->matiral.color.red, plane->matiral.color.green, plane->matiral.color.blue);
    printf("Transform Matrix:\n");
    mat_print(plane->transform);
    printf("Inverse Transform Matrix:\n");
    mat_print(plane->inv_transform);
    printf("Inverse Transpose Matrix:\n");
    mat_print(plane->inv_transpose);
}

void ray_reset_transform_obj(t_object *obj)
{
    if (obj->type == OBJ_PLANE)
    {
        t_plane *plane = &obj->u_data.plane;

        // Reset transformation matrices
        mat_free(&plane->transform);
        mat_free(&plane->inv_transform);
        mat_free(&plane->inv_transpose);

        plane->transform = mat_gener_identity(4);
        plane->inv_transform = mat_gener_identity(4);
        plane->inv_transpose = mat_gener_identity(4);

        // Reset the normal vector to the base normal
        plane->normal = plane->base_normal;

        printf("Plane transform reset:\n");
        mat_print(plane->transform);
        printf("Reset plane normal: (%f, %f, %f)\n", plane->normal.x, plane->normal.y, plane->normal.z);
    }
}
int key_loop(int keycode, t_minirt *rt_struct)
{
    // t_minirt *rt_struct = (t_minirt *)param;
    t_list_  *current = rt_struct->word;

    // Iterate over objects to find a plane
    t_object *plane = NULL;
    t_object *sphere = NULL;
    while (current)
    {
        t_object *obj = (t_object *)current->content;
        if (obj->type == OBJ_PLANE)
        {
            plane = obj;    return (1);
            // print_plane(&obj->u_data.plane);
            break;
        }
        // else if ( obj->type == OBJ_SPHERE)
        // {
        //     sphere = obj;
        //     break;
        // }
        current = current->next;
    }

    // if (sphere)
    // {
    //     if (keycode == KEY_Q)
    //     {
    //         sphere->u_data.sphere.center.z += 10;
    //     }
    //     canva_update(rt_struct);
    // }

    // Ensure the plane exists before applying transformations
    if (plane)
    {
        if (keycode == KEY_Z) { // Rotate plane around Z-axis
            rotate_plane(plane, 'z', ROTATION_SPEED, &rt_struct->scene.world.camera);
        } else if (keycode == KEY_X) { // Rotate plane around X-axis
            rotate_plane(plane, 'x', ROTATION_SPEED, &rt_struct->scene.world.camera);
        } else if (keycode == KEY_Y) { // Rotate plane around Y-axis
            rotate_plane(plane, 'y', ROTATION_SPEED, &rt_struct->scene.world.camera);}
        else if (keycode == KEY_MINUS){
            plane->u_data.plane.center.y += 10;
            
        }
        else if (keycode == KEY_R) { // Reset plane transformations
            ray_reset_transform_obj(plane);
        }
        canva_update(rt_struct);
    }

    if (keycode == KEY_UP || keycode == KEY_DOWN || 
        keycode == KEY_LEFT || keycode == KEY_RIGHT || 
        keycode == KEY_W || keycode == KEY_S) {
        camera_move(&rt_struct->scene.world.camera, keycode);
    }
    else if (keycode == NUMKEY_1) { // Rotate camera left (yaw)
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
		rt_struct->luz.point.x +=0.1;
	}

	else if(keycode == KEY_P)
	{
		rt_struct->luz.point.x -=0.1;
	}

	else if(keycode == KEY_I)
	{
		rt_struct->luz.point.y +=0.1;
	}

	else if(keycode == KEY_K)
	{
		rt_struct->luz.point.y -=0.1;
	}
	else if(keycode == KEY_L)
	{
		rt_struct->luz.point.z +=0.1;
	}
	else if(keycode == KEY_J)
	{
		rt_struct->luz.point.z -=0.1;
	}
    else if (keycode == KEY_ESC) {
        mlx_destroy_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind);
        exit(0);
    }
    return (1);
}