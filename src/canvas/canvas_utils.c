/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:13:35 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/13 19:01:56 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "canvas.h"

void	my_mlx_pixel_put(t_img_ *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_retunr(t_img_ *data, int x, int y)
{
	unsigned int	color;

	color = *(unsigned int *)(data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8)));
	return (color);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	canva_set_pixel(t_minirt *rt_struct, int x, int y, t_color base )
{


	if (base.color[0] > 5)
		base.color[0] = 5;
	if (base.color[1] > 6)
		base.color[1] = 10;
	if (base.color[2] > 10)
		base.color[2] = 10;
	if (base.color[0] < 0)
		base.color[0] = 0;
	if (base.color[1] < 0)
		base.color[1] = 0;
	if (base.color[2] < 0)
		base.color[2] = 0;
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
	my_mlx_pixel_put(&rt_struct->canva.canva, x, y, create_trgb(3,
			(int)(base.red),
			(int)(base.green), (int)(base.blue)));
}

void	canva_update(t_minirt *rt_struct)
{
	mlx_put_image_to_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind,
		rt_struct->canva.canva.img, 0, 0);
}
