/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_navigator_lines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:34:47 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/18 09:29:11 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "axis.h"
#include <math.h>

/**
 * Draw a thick line
 */
void	draw_thick_line(t_img_ *img, t_point start, t_point end, int color)
{
	int		i;
	int		j;
	t_point	offset_start;
	t_point	offset_end;

	i = 0;
	while (i < AXIS_THICKNESS)
	{
		j = 0;
		while (j < AXIS_THICKNESS)
		{
			offset_start.x = start.x + i;
			offset_start.y = start.y + j;
			offset_end.x = end.x + i;
			offset_end.y = end.y + j;
			draw_line(img, offset_start, offset_end, color);
			j++;
		}
		i++;
	}
}

/**
 * Transform a point using the camera's view matrix
 * This is the key function that makes the axis rotate with the camera
 */
static t_point	transform_point(t_camera_ms *cam, t_point point)
{
	t_point	transformed;

	transformed.x = point.x * cam->tranform_matrix.matr[0][0] + \
					point.y * cam->tranform_matrix.matr[0][1] + \
					point.z * cam->tranform_matrix.matr[0][2];
	transformed.y = point.x * cam->tranform_matrix.matr[1][0] + \
					point.y * cam->tranform_matrix.matr[1][1] + \
					point.z * cam->tranform_matrix.matr[1][2];
	transformed.z = point.x * cam->tranform_matrix.matr[2][0] + \
					point.y * cam->tranform_matrix.matr[2][1] + \
					point.z * cam->tranform_matrix.matr[2][2];
	transformed.w = 0;
	return (transformed);
}

/**
 * Project a 3D point to screen coordinates
 */
t_point	proj_point(t_camera_ms *cam, t_point point)
{
	double	perspective;
	double	scale;
	t_point	transformed;

	transformed = transform_point(cam, point);
	perspective = 5.0 + transformed.z;
	if (perspective < 0.1)
		perspective = 0.1;
	scale = AXIS_SIZE / perspective;
	return (create_point(WALL_X - AXIS_OFFSET + transformed.x * scale,
			WALL_Y - AXIS_OFFSET - transformed.y * scale, 0));
}

/**
 * Draw the axis cube navigator with the Blender-style orientation indicator
 */
void	draw_axis_navigator(t_minirt *rt_struct, t_img_ *target)
{
	t_point	ori;
	t_point	end;

	ori = proj_point(&rt_struct->camera, create_point(0, 0, 0));
	end = proj_point(&rt_struct->camera, create_point(1, 0, 0));
	draw_thick_line(target, ori, end, COLOR_X);
	end = proj_point(&rt_struct->camera, create_point(0, 1, 0));
	draw_thick_line(target, ori, end, COLOR_Y);
	end = proj_point(&rt_struct->camera, create_point(0, 0, 1));
	draw_thick_line(target, ori, end, COLOR_Z);
}
