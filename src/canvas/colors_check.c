/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:41:36 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/21 22:20:49 by rerodrig         ###   ########.fr       */
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

void	clamp_color(t_color *color, double min, double max)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color->color[i] > max)
			color->color[i] = max;
		if (color->color[i] < min)
			color->color[i] = min;
		color->color[i] *= 255;
		if (color->color[i] > 255)
			color->color[i] = 255;
		if (color->color[i] < 0)
			color->color[i] = 0;
		i++;
	}
}
