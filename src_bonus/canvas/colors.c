/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:42:48 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/01 18:12:36 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "canvas_struct.h"

t_color	c_new(double red, double green, double blue)
{
	t_color	color;

	color.blue = blue;
	color.green = green;
	color.red = red;
	return (color);
}

t_color	c_adding(t_color c1, t_color c2)
{
	return (c_new(c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue));
}

t_color	c_subtracting(t_color c1, t_color c2)
{
	return (c_new(c1.red - c2.red
			, c1.green - c2.green, c1.blue - c2.blue));
}

t_color	c_scalar_multipl(t_color c1, double scala)
{
	return (c_new(c1.red * scala, c1.green * scala, c1.blue * scala));
}

t_color	c_multipl(t_color c1, t_color c2)
{
	return (c_new(c1.red * c2.red
			, c1.green * c2.green, c1.blue * c2.blue));
}
