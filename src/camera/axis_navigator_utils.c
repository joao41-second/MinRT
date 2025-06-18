/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_navigator_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:34:47 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/02 11:17:52 by rerodrig         ###   ########.fr       */
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
static void	initialize_line(t_line *line, t_point start, t_point end)
{
	line->x0 = start.x;
	line->y0 = start.y;
	line->x1 = end.x;
	line->y1 = end.y;
	line->dx = abs(line->x1 - line->x0);
	line->dy = -abs(line->y1 - line->y0);
	if (line->x0 < line->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y0 < line->y1)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx + line->dy;
}

static void	update_line_position(t_line *line, int *e2)
{
	*e2 = 2 * line->err;
	if (*e2 >= line->dy)
	{
		line->err += line->dy;
		line->x0 += line->sx;
	}
	if (*e2 <= line->dx)
	{
		line->err += line->dx;
		line->y0 += line->sy;
	}
}

static void	draw_line_segment(t_img_ *img, t_line *line, int color)
{
	int	e2;

	while (1)
	{
		draw_pixel(img, line->x0, line->y0, color);
		if (line->x0 == line->x1 && line->y0 == line->y1)
			break ;
		update_line_position(line, &e2);
	}
}

void	draw_line(t_img_ *img, t_point start, t_point end, int color)
{
	t_line	line;

	initialize_line(&line, start, end);
	draw_line_segment(img, &line, color);
}
