/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_navigator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:34:47 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/09 12:06:39 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "axis.h"
#include <math.h>

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
void	init_edges(int edges[12][2])
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
static void	draw_cube_edge(t_cube_ctx *ctx, int i)
{
	t_point		start;
	t_point		end;
	int			color;

	start = proj_point(&ctx->rt->camera,
			create_point(ctx->vertices[ctx->edges[i][0]][0],
				ctx->vertices[ctx->edges[i][0]][1],
				ctx->vertices[ctx->edges[i][0]][2]));
	end = proj_point(&ctx->rt->camera,
			create_point(ctx->vertices[ctx->edges[i][1]][0],
				ctx->vertices[ctx->edges[i][1]][1],
				ctx->vertices[ctx->edges[i][1]][2]));
	color = 0x00888888;
	if (i < 4)
		color = 0x003333AA;
	else if (i < 8)
		color = 0x000000FF;
	else if (i == 8 || i == 11)
		color = 0x0033AA33;
	else if (i == 9 || i == 10)
		color = 0x00AA3333;
	draw_line(ctx->target, start, end, color);
}

/**
 * Draw the orientation cube
 * This function draws a cube around the axis navigator to create a more robust
 * orientation indicator.
 */
void	draw_orientation_cube(t_minirt *rt_struct, t_img_ *target)
{
	double		vertices[8][3];
	int			edges[12][2];
	int			i;
	t_cube_ctx	ctx;

	init_edges(edges);
	init_vertices(vertices, CUBE_SIZE);
	ctx.rt = rt_struct;
	ctx.target = target;
	ctx.vertices = vertices;
	ctx.edges = edges;
	while (i < 12)
	{
		draw_cube_edge(&ctx, i);
		i++;
	}
}

void	draw_cube_labels(t_minirt *rt, t_img_ *target)
{
	static double	axes[3][3] = {{0.5, 0, 0}, {0, 0.5, 0}, {0, 0, 0.5}};
	t_point			screen;
	int				i;
	char			*label;

	i = 0;
	while (i < 3)
	{
		screen = proj_point(&rt->camera,
				create_point(axes[i][0], axes[i][1], axes[i][2]));
		if (i == 0)
			label = "X";
		else if (i == 1)
			label = "Y";
		else
			label = "Z";
		mlx_string_put(rt->canva.mlx, rt->canva.mlx_wind,
			(int)screen.x + 5, (int)screen.y, 0x00FFFFFF, label);
		i++;
	}
}
