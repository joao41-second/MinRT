/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:41:36 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 17:00:18 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "canvas_struct.h"

int	c_chek_iqual_color(t_color a, t_color b)
{
	int	i;

	i = 0;
	if (fabs(a.color[i] - b.color[i]) < EPSILON)
	{
		i++;
		if (fabs(a.color[i] - b.color[i]) < EPSILON)
		{
			i++;
			if (fabs(a.color[i] - b.color[i]) < EPSILON)
				return (TRUE);
		}
	}
	return (FALSE);
}

void	c_print(t_color color)
{
	printf("color %f %f %f \n", color.red, color.green, color.blue);
}

double	c_rgb_to_heihte(t_color color)
{
	return (0.2126 * color.red + 0.7152 * color.green + 0.0722 * color.blue);
}

void	canva_update(t_minirt *rt_struct)
{
	mlx_put_image_to_window(rt_struct->canva.mlx, rt_struct->canva.mlx_wind,
		rt_struct->canva.canva.img, 0, 0);
}

t_color c_average(t_color c1, t_color c2) {
    t_color result;
    result.red = (c1.red + c2.red) / 2.0f;
    result.green = (c1.green + c2.green) / 2.0f;
    result.blue = (c1.blue + c2.blue) / 2.0f;
    return result;
}
