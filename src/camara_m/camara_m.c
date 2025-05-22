/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camara_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:40:30 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 11:34:41 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "../ray/ray_struct.h"

t_ray	cm_ray_for_pixel(t_camera_ms cam, double px, double py)
{
	t_ray	ret;
	double	xoffset;
	double	yoffset;
	t_tuple	pixel;
	t_tuple	origin;

	xoffset = (px + 0.5) * cam.pixel_size;
	yoffset = (py + 0.5) * cam.pixel_size;
	pixel = mat_x_tuple(create_point(cam.half_width
				- xoffset, cam.half_height - yoffset, -1),
			cam.inv_tranform_matrix);
	origin = mat_x_tuple(cam.origin, cam.inv_tranform_matrix);
	ret.o = origin;
	ret.d = normalize(sub_tuples(pixel, origin));
	return (ret);
}

void	cm_pixle_paint(t_minirt *rt_struct, int min_y, int min_x, int scal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < scal)
	{
		x = -1;
		while (++x < scal)
			canva_set_pixel(rt_struct, min_x + x, min_y + y, rt_struct->color);
	}
}

void	cm_windo_put(t_minirt *rt_struct, int x_, int y_, int resul)
{
	t_ray	ray;
	int		x;
	int		y;

	y = 0;
	rt_struct->cam = cm_ray_for_pixel(rt_struct->cam_m,
			(double)x_ / 2, (double)y_ / 2);
	while (y < y_)
	{
		x = 0;
		while (x < x_)
		{
			ray = unified_camera_generate_ray(&rt_struct->camera, x, y);
			rt_struct->color = lig_color_at(rt_struct, ray);
			cm_pixle_paint(rt_struct, y, x, resul);
			x += resul;
		}
		y += resul;
	}
}
