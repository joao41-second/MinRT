/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:48:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/19 13:31:29 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minRT.h"
#include "camera.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


void camera_init(t_camera *cam, t_point origin, t_vector direction, double fov)
{
    cam->origin = origin;
    cam->direction = normalize(direction);
    cam->aspect_ratio = (double)WALL_X / WALL_Y;
    cam->fov = fov;
    camera_update_view(cam);
}


void camera_rotate(t_camera *camera, double dx, double dy)
{
    t_vector forward = normalize(camera->direction);
    t_vector world_up;
    t_vector right;
    t_matrix pitch;
    t_matrix yaw;
    if (fabs(forward.y) > 0.999)
        world_up = create_vector(0, 0, 1);
    else
        world_up = create_vector(0, 1, 0);
    right = normalize(cross_product(forward, world_up));
    pitch = mat_rotate(right, dy * ROTATION_SPEED);
    forward = normalize(mat_x_tuple(forward, pitch));
    world_up = normalize(cross_product(right, forward));
    yaw   = mat_rotate(world_up, dx * ROTATION_SPEED);
    forward = normalize(mat_x_tuple(forward, yaw));
    camera->direction = forward;
    camera_update_view(camera);
}

void camera_update_view(t_camera *cam)
{
    t_vector forward = normalize(cam->direction);
    t_vector world_up;
    t_vector right;
    t_vector true_up;
    
    if (fabs(forward.y) > 0.999)
        world_up = create_vector(0, 0, 1);
    else
        world_up = create_vector(0, 1, 0);
    right   = normalize(cross_product(forward, world_up));
    true_up = cross_product(right, forward);
    printf("camera_update_view:\n");
    printf("Forward: (%f, %f, %f)\n", forward.x, forward.y, forward.z);
    printf("World Up: (%f, %f, %f)\n", world_up.x, world_up.y, world_up.z);
    printf("Right: (%f, %f, %f)\n", right.x, right.y, right.z);
    printf("True Up: (%f, %f, %f)\n", true_up.x, true_up.y, true_up.z);
    cam->view_matrix     = mat_lookat(cam->origin,
                                      add_tuples(cam->origin, forward),
                                      true_up);
    cam->inv_view_matrix = mat_inv(cam->view_matrix);
}

t_ray camera_generate_ray(t_camera *cam, double x, double y)
{
    double scale = tan(cam->fov * 0.5 * M_PI / 180.0);
    double aspect_ratio = cam->aspect_ratio;
    double xndc = (2.0 * (x + 0.5) / WALL_X - 1.0) * aspect_ratio * scale;
    double yndc = (1.0 - 2.0 * (y + 0.5) / WALL_Y) * scale;
    t_vector ray_dir = create_vector(xndc, yndc, 1.0);
    
    ray_dir = normalize(mat_x_tuple(ray_dir, cam->inv_view_matrix));
    return ray_gener(cam->origin, ray_dir);
}


void camera_move(t_camera *cam, int keycode)
{
    t_vector forward = normalize(cam->direction);
    t_vector world_up;
    
    if (fabs(forward.y) > 0.999)
        world_up = create_vector(0, 0, 1);
    else
        world_up = create_vector(0, 1, 0);
        
    t_vector right = normalize(cross_product(forward, world_up));
    t_vector true_up = cross_product(right, forward);

    if (keycode == KEY_UP)
        cam->origin = add_tuples(cam->origin, scalar_mult_tuples(forward, MOVE_SPEED));
    else if (keycode == KEY_DOWN)
        cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(forward, MOVE_SPEED));
    else if (keycode == KEY_LEFT)
        cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(right, MOVE_SPEED));
    else if (keycode == KEY_RIGHT)
        cam->origin = add_tuples(cam->origin, scalar_mult_tuples(right, MOVE_SPEED));
    else if (keycode == KEY_W)
        cam->origin = add_tuples(cam->origin, scalar_mult_tuples(world_up, MOVE_SPEED));
    else if (keycode == KEY_S)
        cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(world_up, MOVE_SPEED));

    camera_update_view(cam);
}

t_matrix mat_lookat(t_point eye, t_point center, t_vector up)
{
    t_vector f = normalize(sub_tuples(center, eye));
    t_vector s = normalize(cross_product(f, up));
    t_vector u = cross_product(s, f);

    t_matrix rotation = mat_gener_identity(4);
    rotation.matr[0][0] = s.x;
    rotation.matr[0][1] = s.y;
    rotation.matr[0][2] = s.z;
    rotation.matr[1][0] = u.x;
    rotation.matr[1][1] = u.y;
    rotation.matr[1][2] = u.z;
    rotation.matr[2][0] = -f.x;
    rotation.matr[2][1] = -f.y;
    rotation.matr[2][2] = -f.z;
    t_matrix translation = mat_gener_trans(-eye.x, -eye.y, -eye.z);
    t_matrix view_matrix = mat_multip(rotation, translation);
    return view_matrix;
}
