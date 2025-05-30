/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:48:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/30 14:32:20 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "camera.h"

t_matrix	mat_rotate(t_vector axis, double angle)
{
	double		cos_a;
	double		sin_a;
	double		one_minus_cos;
	t_matrix	rotation;

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
	return (rotation);
}

static t_vector	apply_rotation(t_vector vector, t_vector axis, double angle)
{
	t_matrix	rotation_matrix;
	t_vector	result;

	rotation_matrix = mat_rotate(axis, angle);
	result = normalize(mat_x_tuple(vector, rotation_matrix));
	mat_free(&rotation_matrix);
	return (result);
}

// void	camera_rotate(t_camera_ms *camera, double dx, double dy)
// {
// 	t_vector	forward;
// 	t_vector	world_up;
// 	t_vector	left;
// 	t_point		original_origin;

// 	forward = normalize(camera->direction);
// 	original_origin = camera->origin;
// 	camera->origin = sub_tuples(camera->origin, create_vector(0, 0, 0));
// 	if (fabs(forward.y) > 0.98)
// 		world_up = create_vector(0, 0, 1);
// 	else
// 		world_up = create_vector(0, 1, 0);
// 	left = normalize(cross_product(forward, world_up));
// 	forward = apply_rotation(forward, left, dy);
// 	world_up = normalize(cross_product(left, forward));
// 	forward = apply_rotation(forward, world_up, dx);
// 	camera->direction = forward;
// 	camera->origin = add_tuples(camera->origin, original_origin);
// 	camera_update_view(camera);
// }

// void	camera_move(t_camera_ms *cam, int k, t_minirt *rt_struct)
// {
// 	t_vector	f;
// 	t_vector	w_up;
// 	t_vector	left;
// 	t_vector	true_up;

// 	f = normalize(cam->direction);
// 	if (fabs(f.y) > 0.999)
// 		w_up = create_vector(0, 0, 1);
// 	else
// 		w_up = create_vector(0, 1, 0);
// 	left = normalize(cross_product(f, w_up));
// 	true_up = cross_product(left, f);
// 	if (k == KEY_UP)
// 		rt_struct->point.y += 0.1;
// 		// cam->origin = add_tuples(cam->origin, scalar_mult_tuples(f, MOVE));
// 	else if (k == KEY_DOWN)
// 		rt_struct->point.y -= 0.1;
// 		// cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(f, MOVE));
// 	else if (k == KEY_LEFT)
// 		rt_struct->point.x -= 0.1;
// 		// cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(left, MOVE));
// 	else if (k == KEY_RIGHT)
// 		rt_struct->point.x += 0.1;
// 		// cam->origin = add_tuples(cam->origin, scalar_mult_tuples(left, MOVE));
// 	else if (k == KEY_W)
// 		rt_struct->point.z += 0.1;
// 		// cam->origin = add_tuples(cam->origin, scalar_mult_tuples(w_up, MOVE));
// 	else if (k == KEY_S)
// 		rt_struct->point.z -= 0.1;
// 		// cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(w_up, MOVE));
// 	camera_update_view(cam);
// }
void	camera_move(t_minirt *rt_struct)
{
    // Update rt_struct->point based on the key pressed
    if (rt_struct->key_pressed == KEY_UP)
        rt_struct->point.y += 0.1;
    else if (rt_struct->key_pressed == KEY_DOWN)
        rt_struct->point.y -= 0.1;
    else if (rt_struct->key_pressed == KEY_LEFT)
        rt_struct->point.x -= 0.1;
    else if (rt_struct->key_pressed == KEY_RIGHT)
        rt_struct->point.x += 0.1;
    else if (rt_struct->key_pressed == KEY_W)
        rt_struct->point.z += 0.1;
    else if (rt_struct->key_pressed == KEY_S)
        rt_struct->point.z -= 0.1;

    // No need to directly modify the camera's transformation matrix here,
    // as it will be recalculated in each frame using rt_struct->point.
}
void	camera_rotate(t_minirt *rt_struct)
{
    // Update rotation values in rt_struct
    if (rt_struct->key_pressed == NUMKEY_1)
        rt_struct->rota_x += ROTATION_SPEED;
    else if (rt_struct->key_pressed == NUMKEY_2)
        rt_struct->rota_x -= ROTATION_SPEED;
    else if (rt_struct->key_pressed == NUMKEY_3)
        rt_struct->rota_y += ROTATION_SPEED;
    else if (rt_struct->key_pressed == NUMKEY_4)
        rt_struct->rota_y -= ROTATION_SPEED;

    // No need to directly modify the camera's transformation matrix here,
    // as it will be recalculated in each frame using rt_struct->rota_x and rt_struct->rota_y.
}