/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:07:37 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/24 11:11:15 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

//create -------------------------------------------------------------
t_tuple	create_tuple(double x, double y, double z, double w)
{
	t_tuple	tuple;

	if (x == -0)
		x = 0;
	if (y == -0)
		y = 0;
	if (z == -0)
		z = 0;
	if (w == -0)
		w = 0;
	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

t_point	create_point(double x, double y, double z)
{
	return (create_tuple(x, y, z, W_POINT));
}

t_vector	create_vector(double x, double y, double z)
{
	return (create_tuple(x, y, z, W_VECTOR));
}
