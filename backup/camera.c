/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:48:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/07 09:13:59 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "camera.h"
#include "../camara_m/camara_m.h" // Include for cm_pixel_size

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Updated to use t_camera_ms instead of t_camera
void camera_init(t_camera_ms *cam, t_point origin, t_vector direction, double fov)
{
    cam->loc = origin;
    cam->dir = normalize(direction);
    cam->x = (double)WALL_X;
    cam->y = (double)WALL_Y;
    cam->field_of_view = fov;
    cam->tranform_matrix = mat_lookat(origin, add_tuples(origin, direction), create_vector(0, 1, 0));
    cam->inv_tranform_matrix = mat_inv(cam->tranform_matrix);
    cm_pixel_size(cam); // Reuse pixel size calculation from camara_m.c
}

t_matrix mat_rotate(t_vector axis, double angle)
{
    double cos_a;
    double sin_a;
    double one_minus_cos;
    t_matrix rotation;
	cos_a = cos(angle);
    sin_a = sin(angle);
    one_minus_cos = 1.0 - cos_a;
    rotation = mat_gener_identity(4);
    axis = normalize(axis);
    rotation.matr[0][0] = cos_a + axis.x * axis.x * one_minus_cos;
    rotation.matr[0][1] = axis.x * axis.y * one_minus_cos - axis.z * sin_a;
    rotation.matr[0][2] = axis.x * axis.z * one_minus_cos + axis.y * sin_a;
    rotation.matr[1][0] = axis.y * axis.x * one_minus_cos + axis.z * sin_a;
    rotation.matr[1][1] = cos_a + axis.y * axis.y * one_minus_cos;
    rotation.matr[1][2] = axis.y * axis.z * one_minus_cos - axis.x * sin_a;
    rotation.matr[2][0] = axis.z * axis.x * one_minus_cos - axis.y * sin_a;
    rotation.matr[2][1] = axis.z * axis.y * one_minus_cos + axis.x * sin_a;
    rotation.matr[2][2] = cos_a + axis.z * axis.z * one_minus_cos;
    return rotation;
}

// Updated to use t_camera_ms
void camera_rotate(t_camera_ms *cam, double dx, double dy)
{
    t_vector forward = normalize(cam->dir);
    t_vector world_up;
    t_vector left;
    t_matrix pitch;
    t_matrix yaw;

    if (fabs(forward.y) > 0.98)
        world_up = create_vector(0, 0, 1);
    else
        world_up = create_vector(0, 1, 0);

    left = normalize(cross_product(forward, world_up));
    pitch = mat_rotate(left, dy);
    forward = normalize(mat_x_tuple(forward, pitch));
    mat_free(&pitch);

    world_up = normalize(cross_product(left, forward));
    yaw = mat_rotate(world_up, dx);
    forward = normalize(mat_x_tuple(forward, yaw));
    mat_free(&yaw);

    cam->dir = forward;
    camera_update_view(cam);
}

// Updated to use t_camera_ms
void camera_update_view(t_camera_ms *cam)
{
    t_vector forward = normalize(cam->dir);
    t_vector world_up;
    t_vector left;
    t_vector true_up;

    if (fabs(forward.y) > 0.98)
        world_up = create_vector(0, 0, 1);
    else
        world_up = create_vector(0, 1, 0);

    left = normalize(cross_product(forward, world_up));
    true_up = cross_product(left, forward);

    cam->tranform_matrix = mat_lookat(cam->loc, add_tuples(cam->loc, forward), true_up);
    cam->inv_tranform_matrix = mat_inv(cam->tranform_matrix);
}

// Updated to use t_camera_ms
void camera_move(t_camera_ms *cam, int keycode)
{
    t_vector forward = normalize(cam->dir);
    t_vector world_up;

    if (fabs(forward.y) > 0.999)
        world_up = create_vector(0, 0, 1);
    else
        world_up = create_vector(0, 1, 0);

    t_vector left = normalize(cross_product(forward, world_up));

    if (keycode == KEY_UP)
        cam->loc = add_tuples(cam->loc, scalar_mult_tuples(forward, MOVE_SPEED));
    else if (keycode == KEY_DOWN)
        cam->loc = sub_tuples(cam->loc, scalar_mult_tuples(forward, MOVE_SPEED));
    else if (keycode == KEY_LEFT)
        cam->loc = sub_tuples(cam->loc, scalar_mult_tuples(left, MOVE_SPEED));
    else if (keycode == KEY_RIGHT)
        cam->loc = add_tuples(cam->loc, scalar_mult_tuples(left, MOVE_SPEED));
    else if (keycode == KEY_W)
        cam->loc = add_tuples(cam->loc, scalar_mult_tuples(world_up, MOVE_SPEED));
    else if (keycode == KEY_S)
        cam->loc = sub_tuples(cam->loc, scalar_mult_tuples(world_up, MOVE_SPEED));

    camera_update_view(cam);
}

t_matrix mat_lookat(t_point eye, t_point center, t_vector up)
{
    t_vector forward = normalize(sub_tuples(center, eye));
    t_vector left = normalize(cross_product(forward, up));  // Changed to left
    t_vector true_up = cross_product(left, forward);
    t_matrix rotation = mat_gener_identity(4);
    
    // Match the matrix construction in lig_view_transform
    rotation.matr[0][0] = left.x;  // Use left instead of s/right
    rotation.matr[0][1] = left.y;
    rotation.matr[0][2] = left.z;
    rotation.matr[1][0] = true_up.x;
    rotation.matr[1][1] = true_up.y;
    rotation.matr[1][2] = true_up.z;
    rotation.matr[2][0] = -forward.x;
    rotation.matr[2][1] = -forward.y;
    rotation.matr[2][2] = -forward.z;
    
    t_matrix translation = mat_gener_trans(-eye.x, -eye.y, -eye.z);
    t_matrix view_matrix = mat_multip(rotation, translation);
    return view_matrix;
}

// Updated to use t_camera_ms
t_ray camera_generate_ray(t_camera_ms *cam, double x, double y)
{
    double scale;
    double aspect_ratio;
    double xndc;
    double yndc;
    t_vector ray_dir;

    scale = tan(cam->field_of_view * 0.5 * M_PI / 180.0);
    aspect_ratio = cam->x / cam->y;
    xndc = (2.0 * (x + 0.5) / cam->x - 1.0) * aspect_ratio * scale;
    yndc = (1.0 - 2.0 * (y + 0.5) / cam->y) * scale;
    ray_dir = create_vector(xndc, yndc, -1.0);
    ray_dir = normalize(mat_x_tuple(ray_dir, cam->inv_tranform_matrix));
    return ray_gener(cam->loc, ray_dir);
}

