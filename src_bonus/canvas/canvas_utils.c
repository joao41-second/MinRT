/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:13:35 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 17:00:23 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "canvas.h"
#include "canvas_struct.h"
#include <unistd.h>

void	my_mlx_pixel_put(t_img_ *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_retunr(t_img_ *data, int x, int y)
{
	unsigned int	color;

	if (x > data->width)
		x = data->width;
	if (y > data->height)
		y = data->height;
	color = *(unsigned int *)(data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8)));
	return (color);
}

int	create_trgb( int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

t_color	c_get_color(int color)
{
	t_color	ret;

	ret.red = (color >> 16 & 0xFF) / 255.0 ;
	ret.green = (color >> 8 & 0xFF) / 255.0 ;
	ret.blue = (color & 0xFF) / 255.0;
	return (ret);
}

void	canva_set_pixel(t_minirt *rt_struct, int x, int y, t_color base )
{
	base.color[0] = base.color[0] * 255;
	base.color[1] = base.color[1] * 255;
	base.color[2] = base.color[2] * 255;
	if (base.color[0] > 255)
		base.color[0] = 255;
	if (base.color[1] > 255)
		base.color[1] = 255;
	if (base.color[2] > 255)
		base.color[2] = 255;
	if (base.color[0] < 0)
		base.color[0] = 0;
	if (base.color[1] < 0)
		base.color[1] = 0;
	if (base.color[2] < 0)
		base.color[2] = 0;
	my_mlx_pixel_put(&rt_struct->canva.canva, x, y, create_trgb((int)(base.red),
			(int)(base.green), (int)(base.blue)));
}
