/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_navigator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:34:47 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/12 11:00:51 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "axis.h"
#include <math.h>

/**
 * Draw a pixel with bounds checking
 */
static void	draw_pixel(t_img_ *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WALL_X || y >= WALL_Y)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
 * Draw a line using Bresenham's algorithm
 */
static void	draw_line(t_img_ *img, t_point start, t_point end, int color)
{
	int		e2;
	t_line	line;

	line.x0 = start.x;
	line.y0 = start.y;
	line.x1 = end.x;
	line.y1 = end.y;
	line.dx = abs(line.x1 - line.x0);
	line.dy = -abs(line.y1 - line.y0);
	line.sx = -1;
	if (line.x0 < line.x1)
		line.sx = 1;
	line.sy = -1;
	if (line.y0 < line.y1)
		line.sy = 1;
	line.err = line.dx + line.dy;
	while (1)
	{
		draw_pixel(img, line.x0, line.y0, color);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		e2 = 2 * line.err;
		if (e2 >= line.dy)
		{
			if (line.x0 == line.x1)
				break ;
			line.err += line.dy;
			line.x0 += line.sx;
		}
		if (e2 <= line.dx)
		{
			if (line.y0 == line.y1)
				break ;
			line.err += line.dx;
			line.y0 += line.sy;
		}
	}
}

/**
 * Draw a thick line
 */
static void	draw_thick_line(t_img_ *img, t_point start, t_point end, int color)
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
static t_point	proj_point(t_camera_ms *cam, t_point point)
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
void	draw_axis_navigator(t_minirt *rt_struct)
{
	t_point	ori;
	t_point	end;
	t_point	lab;

	ori = proj_point(&rt_struct->camera, create_point(0, 0, 0));
	end = proj_point(&rt_struct->camera, create_point(1, 0, 0));
	draw_thick_line(&rt_struct->canva.canva, ori, end, COLOR_X);
	end = proj_point(&rt_struct->camera, create_point(0, 1, 0));
	draw_thick_line(&rt_struct->canva.canva, ori, end, COLOR_Y);
	end = proj_point(&rt_struct->camera, create_point(0, 0, 1));
	draw_thick_line(&rt_struct->canva.canva, ori, end, COLOR_Z);
	lab = proj_point(&rt_struct->camera, create_point(1.2, 0, 0));
	// mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, (int)lab.x, \
	// 	(int)lab.y, COLOR_X, "X");
	// lab = proj_point(&rt_struct->camera, create_point(0, 1.2, 0));
	// mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, (int)lab.x, \
	// 	(int)lab.y, COLOR_Y, "Y");
	// lab = proj_point(&rt_struct->camera, create_point(0, 0, 1.2));
	// mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, (int)lab.x, \
	// 	(int)lab.y, COLOR_Z, "Z");
}

// Initialize the vertices of the cube
static void	init_vertices(double vertices[8][3], double cube_size)
{
	int					i;
	static const double	base_vertices[8][3] = {
	{-1, -1, -1},
	{1, -1, -1},
	{1, 1, -1},
	{-1, 1, -1},
	{-1, -1, 1},
	{1, -1, 1},
	{1, 1, 1},
	{-1, 1, 1}
	};

	i = 0;
	while (i < 8)
	{
		vertices[i][0] = base_vertices[i][0] * cube_size;
		vertices[i][1] = base_vertices[i][1] * cube_size;
		vertices[i][2] = base_vertices[i][2] * cube_size;
		i++;
	}
}

// Initialize the edges of the cube
static void	init_edges(int edges[12][2])
{
	int					i;
	static const int	predefined_edges[12][2] = {
	{0, 1}, {1, 2}, {2, 3}, {3, 0},
	{4, 5}, {5, 6}, {6, 7}, {7, 4},
	{0, 4}, {1, 5}, {2, 6}, {3, 7}
	};

	i = 0;
	while (i < 12)
	{
		edges[i][0] = predefined_edges[i][0];
		edges[i][1] = predefined_edges[i][1];
		i++;
	}
}

/**
 * Draw a cube edge
 */
static void	draw_cube_edge(t_minirt *rt_struct, double verti[8][3], \
		int edges[12][2], int i)
{
	t_point	start;
	t_point	end;
	int		color;

	start = proj_point(&rt_struct->camera, \
		create_point(verti[edges[i][0]][0], verti[edges[i][0]][1], \
		verti[edges[i][0]][2]));
	end = proj_point(&rt_struct->camera, \
			create_point(verti[edges[i][1]][0], verti[edges[i][1]][1], \
			verti[edges[i][1]][2]));
	color = 0x00888888;
	if (i < 4)
		color = 0x003333AA;
	else if (i < 8)
		color = 0x000000FF;
	else if (i == 8 || i == 11)
		color = 0x0033AA33;
	else if (i == 9 || i == 10)
		color = 0x00AA3333;
	draw_line(&rt_struct->canva.canva, start, end, color);
}

/**
 * Draw the orientation cube
 * This function draws a cube around the axis navigator to create a more robust
 * orientation indicator.
 */
void	draw_orientation_cube(t_minirt *rt_struct)
{
	double	vertices[8][3];
	int		edges[12][2];
	int		i;

	i = 0;
	init_edges(edges);
	init_vertices(vertices, CUBE_SIZE);
	while (i < 12)
	{
		draw_cube_edge(rt_struct, vertices, edges, i);
		i++;
	}
}
void draw_cube_labels(t_minirt *rt) {
	float axes[3][3] = {{0.5, 0, 0}, {0, 0.5, 0}, {0, 0, 0.5}};
	t_point screen;
	int i = 0;

	while (i < 3) {
		screen = proj_point(&rt->camera, 
							create_point(axes[i][0], axes[i][1], axes[i][2]));
		char *label = (i == 0) ? "X" : (i == 1) ? "Y" : "Z";
		mlx_string_put(rt->canva.mlx, rt->canva.mlx_wind, 
					   (int)screen.x + 5, (int)screen.y, 0x00FFFFFF, label);
		i++;
	}
}
/**
 * Main function to draw the complete navigator
 * This should be called in your canva_loop function
 */
void	draw_navigator(t_minirt *rt_struct)
{
	draw_axis_navigator(rt_struct);
	draw_orientation_cube(rt_struct);
	// draw_cube_labels(rt_struct);
}
