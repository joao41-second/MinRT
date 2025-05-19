/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:48:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/19 11:39:37 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "camera.h"
// #include "camera.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
void camera_init(t_camera_ms *cam, t_point origin, t_vector direction, double fov)
{
    cam->origin = origin;
    cam->direction = normalize(direction);
    cam->aspect_ratio = (double)WALL_X / WALL_Y;
    
    cam->fov = fov;
    cam->field_of_view = fov * (M_PI / 180.0);
    cam->x = WALL_X;
    cam->y = WALL_Y;
    double half_view = tan(cam->field_of_view / 2);
    cam->half_width = half_view;
    cam->half_height = half_view / cam->aspect_ratio;
    cam->pixel_size = (cam->half_width * 2) / cam->x;
    cam->mode = CAM_MODE_R;
    camera_update_view(cam);
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

void camera_rotate(t_camera_ms *camera, double dx, double dy)
{
    t_vector forward = normalize(camera->direction);
    t_vector world_up;
    t_vector left;  // Changed from right
    t_matrix pitch;
    t_matrix yaw;
    
    if (fabs(forward.y) > 0.98)
        world_up = create_vector(0, 0, 1);
    else
        world_up = create_vector(0, 1, 0);
    
    left = normalize(cross_product(forward, world_up));  // Changed to left
    pitch = mat_rotate(left, dy);  // Use left for rotation
    forward = normalize(mat_x_tuple(forward, pitch));
    mat_free(&pitch);
    
    world_up = normalize(cross_product(left, forward));  // Changed order
    yaw = mat_rotate(world_up, dx);
    forward = normalize(mat_x_tuple(forward, yaw));
    mat_free(&yaw);
    
    camera->direction = forward;
    camera_update_view(camera);
}

void camera_update_view(t_camera_ms *cam)
{
    t_vector forward = normalize(cam->direction);
    t_vector world_up;
    t_vector left;
    t_vector true_up;
    
    if (fabs(forward.y) > 0.98)
        world_up = create_vector(0, 0, 1);
    else
        world_up = create_vector(0, 1, 0);
    
    left = normalize(cross_product(forward, world_up));
    true_up = cross_product(left, forward);
    
    // printf("camera_update_view:\n");
    // printf("Forward: (%f, %f, %f)\n", forward.x, forward.y, forward.z);
    // printf("World Up: (%f, %f, %f)\n", world_up.x, world_up.y, world_up.z);
    // printf("Left: (%f, %f, %f)\n", left.x, left.y, left.z);
    // printf("True Up: (%f, %f, %f)\n", true_up.x, true_up.y, true_up.z);
    
    cam->tranform_matrix = mat_lookat(cam->origin,
                                  add_tuples(cam->origin, forward),
                                  true_up);
    cam->inv_tranform_matrix = mat_inv(cam->tranform_matrix);
}

t_ray camera_generate_ray(t_camera_ms *cam, double x, double y)
{
    double scale;
    double aspect_ratio;
    double xndc;
    double yndc;
    t_vector ray_dir;
    
    scale = tan(cam->fov * 0.5 * M_PI / 180.0);
    aspect_ratio = cam->aspect_ratio;
    xndc = (2.0 * (x + 0.5) / WALL_X - 1.0) * aspect_ratio * scale;
    yndc = (1.0 - 2.0 * (y + 0.5) / WALL_Y) * scale;
    ray_dir = create_vector(xndc, yndc, -1.0);
    ray_dir = normalize(mat_x_tuple(ray_dir, cam->inv_tranform_matrix));
    return ray_gener(cam->origin, ray_dir);
}


t_ray unified_camera_generate_ray(t_camera_ms *cam, double x, double y)
{
    if (cam->mode == CAM_MODE_J) {
        return cm_ray_for_pixel(*cam, x, y);
    } else {
        return camera_generate_ray(cam, x, y);
    }
}

void unified_camera_set_mode(t_camera_ms *cam, t_camera_mode mode)
{

    if (!cam)
        return;
    cam->mode = mode;
    printf("Camera mode switched to: %s\n", 
           mode == CAM_MODE_J ? "Camera Joao" : "Camera Rei");
}
void camera_move(t_camera_ms *cam, int keycode)
{
    t_vector forward = normalize(cam->direction);
    t_vector world_up;
    
    if (fabs(forward.y) > 0.999)
        world_up = create_vector(0, 0, 1);
    else
        world_up = create_vector(0, 1, 0);
    
    t_vector left = normalize(cross_product(forward, world_up));  // Changed to left
    t_vector true_up = cross_product(left, forward);
    
    if (keycode == KEY_UP)
        cam->origin = add_tuples(cam->origin, scalar_mult_tuples(forward, MOVE_SPEED));
    else if (keycode == KEY_DOWN)
        cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(forward, MOVE_SPEED));
    else if (keycode == KEY_LEFT)
        cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(left, MOVE_SPEED));  // Use left
    else if (keycode == KEY_RIGHT)
        cam->origin = add_tuples(cam->origin, scalar_mult_tuples(left, MOVE_SPEED));  // Note: may need to flip the sign here
    else if (keycode == KEY_W)
        cam->origin = add_tuples(cam->origin, scalar_mult_tuples(world_up, MOVE_SPEED));
    else if (keycode == KEY_S)
        cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(world_up, MOVE_SPEED));
    
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
    t_matrix tranform_matrix = mat_multip(rotation, translation);
    return tranform_matrix;
}

void camera_set_view_transform(t_camera_ms *cam, t_point from, t_point to, t_vector up) {
    t_vector forward = normalize(sub_tuples(to, from));
    t_vector left = normalize(cross_product(forward, normalize(up)));
    t_vector true_up = cross_product(left, forward);

    cam->tranform_matrix = mat_gener_identity(4);
    cam->tranform_matrix.matr[0][0] = left.x;
    cam->tranform_matrix.matr[0][1] = left.y;
    cam->tranform_matrix.matr[0][2] = left.z;
    cam->tranform_matrix.matr[1][0] = true_up.x;
    cam->tranform_matrix.matr[1][1] = true_up.y;
    cam->tranform_matrix.matr[1][2] = true_up.z;
    cam->tranform_matrix.matr[2][0] = -forward.x;
    cam->tranform_matrix.matr[2][1] = -forward.y;
    cam->tranform_matrix.matr[2][2] = -forward.z;

    t_matrix translation = mat_gener_trans(-from.x, -from.y, -from.z);
    cam->tranform_matrix = mat_multip(cam->tranform_matrix, translation);
    cam->inv_tranform_matrix = mat_inv(cam->tranform_matrix);
}

