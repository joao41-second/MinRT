/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:13:35 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/18 09:41:58 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "canvas.h"
#include "canvas_struct.h"
#include "menu/menu.h"
#include "../camera/axis.h"
#include <unistd.h>

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

void	canva_set_pixel(t_minirt *rt_struct, int x, int y, t_color base)
{
	clamp_color(&base, 0, 10);
	my_mlx_pixel_put(&rt_struct->canva.canva, x, y, create_trgb(3,
			(int)(base.red), (int)(base.green), (int)(base.blue)));
}

// void	canva_update(t_minirt *rt_struct)
// {
// 	mlx_put_image_to_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind,
// 		rt_struct->canva.canva.img, 0, 0);
// }

void	canva_update(t_minirt *rt_struct)
{
	draw_axis_navigator(rt_struct, &rt_struct->canva.canva);
	draw_orientation_cube(rt_struct, &rt_struct->canva.canva);
	mlx_put_image_to_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind,
		rt_struct->canva.canva.img, 0, 0);
	draw_cube_labels(rt_struct);
	if (rt_struct->menu)
		ft_menu(rt_struct);
	else
		mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind,
			W_POS, WALL_Y - HEIGHT_POS * 2, WHITE, "Press 'TAB' for menu");
	camera_update_view(&rt_struct->camera);
}
