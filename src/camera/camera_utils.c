/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:48:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/22 10:07:22 by rerodrig         ###   ########.fr       */
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

void	camera_rotate(t_camera_ms *camera, double dx, double dy)
{
	t_vector	forward;
	t_vector	world_up;
	t_vector	left;
	t_point		original_origin;

	forward = normalize(camera->direction);
	original_origin = camera->origin;
	camera->origin = sub_tuples(camera->origin, create_vector(0, 0, 0));
	if (fabs(forward.y) > 0.98)
		world_up = create_vector(0, 0, 1);
	else
		world_up = create_vector(0, 1, 0);
	left = normalize(cross_product(forward, world_up));
	forward = apply_rotation(forward, left, dy);
	world_up = normalize(cross_product(left, forward));
	forward = apply_rotation(forward, world_up, dx);
	camera->direction = forward;
	camera->origin = add_tuples(camera->origin, original_origin);
	camera_update_view(camera);
}

void	camera_move(t_camera_ms *cam, int k)
{
	t_vector	f;
	t_vector	w_up;
	t_vector	left;
	t_vector	true_up;

	f = normalize(cam->direction);
	if (fabs(f.y) > 0.999)
		w_up = create_vector(0, 0, 1);
	else
		w_up = create_vector(0, 1, 0);
	left = normalize(cross_product(f, w_up));
	true_up = cross_product(left, f);
	if (k == KEY_UP)
		cam->origin = add_tuples(cam->origin, scalar_mult_tuples(f, MOVE));
	else if (k == KEY_DOWN)
		cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(f, MOVE));
	else if (k == KEY_LEFT)
		cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(left, MOVE));
	else if (k == KEY_RIGHT)
		cam->origin = add_tuples(cam->origin, scalar_mult_tuples(left, MOVE));
	else if (k == KEY_W)
		cam->origin = add_tuples(cam->origin, scalar_mult_tuples(w_up, MOVE));
	else if (k == KEY_S)
		cam->origin = sub_tuples(cam->origin, scalar_mult_tuples(w_up, MOVE));
	camera_update_view(cam);
}
