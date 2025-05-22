/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:48:53 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/22 10:08:02 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "camera.h"

void	camera_init(t_camera_ms *cam, t_point ori, t_vector dir, double fov)
{
	double	half_view;

	cam->origin = ori;
	cam->direction = normalize(dir);
	cam->aspect_ratio = (double)WALL_X / WALL_Y;
	cam->fov = fov;
	cam->field_of_view = fov * (M_PI / 180.0);
	cam->x = WALL_X;
	cam->y = WALL_Y;
	half_view = tan(cam->field_of_view / 2);
	cam->half_width = half_view;
	cam->half_height = half_view / cam->aspect_ratio;
	cam->pixel_size = (cam->half_width * 2) / cam->x;
	cam->mode = CAM_MODE_R;
	camera_update_view(cam);
}

void	camera_update_view(t_camera_ms *cam)
{
	t_vector	forward;
	t_vector	world_up;
	t_vector	left;
	t_vector	true_up;

	forward = normalize(cam->direction);
	if (fabs(forward.y) > 0.98)
		world_up = create_vector(0, 0, 1);
	else
		world_up = create_vector(0, 1, 0);
	left = normalize(cross_product(forward, world_up));
	true_up = cross_product(left, forward);
	cam->tranform_matrix = mat_lookat(cam->origin,
			add_tuples(cam->origin, forward), true_up);
	cam->inv_tranform_matrix = mat_inv(cam->tranform_matrix);
}

t_ray	camera_generate_ray(t_camera_ms *cam, double x, double y)
{
	double		scale;
	double		aspect_ratio;
	double		xndc;
	double		yndc;
	t_vector	ray_dir;

	scale = tan(cam->fov * 0.5 * M_PI / 180.0);
	aspect_ratio = cam->aspect_ratio;
	xndc = (2.0 * (x + 0.5) / WALL_X - 1.0) * aspect_ratio * scale;
	yndc = (1.0 - 2.0 * (y + 0.5) / WALL_Y) * scale;
	ray_dir = create_vector(xndc, yndc, -1.0);
	ray_dir = normalize(mat_x_tuple(ray_dir, cam->inv_tranform_matrix));
	return (ray_gener(cam->origin, ray_dir));
}

t_ray	unified_camera_generate_ray(t_camera_ms *cam, double x, double y)
{
	if (cam->mode == CAM_MODE_J)
		return (cm_ray_for_pixel(*cam, x, y));
	else
		return (camera_generate_ray(cam, x, y));
}

void	unified_camera_set_mode(t_camera_ms *cam, t_camera_mode mode)
{
	if (!cam)
		return ;
	cam->mode = mode;
}
