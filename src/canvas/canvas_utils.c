/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:13:35 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/18 15:46:25 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

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
 	my_mlx_pixel_put(&rt_struct->canva.canva, x, y, create_trgb(1,
			(int)(base.red*255), (int)(base.green*255), (int)(base.blue*255)));
}

void	canva_update(t_minirt *rt_struct)
{
	mlx_put_image_to_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind,
		rt_struct->canva.canva.img, 0, 0);
}
