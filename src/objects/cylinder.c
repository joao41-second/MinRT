/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:46:08 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/21 21:22:07 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"

t_cylinder	create_cylinder(t_point center, t_vector orientation, double radius,
	double height)
{
	t_cylinder	cylinder;

	cylinder.center = center;
	cylinder.orientation = normalize(orientation);
	cylinder.radius = radius;
	cylinder.height = height;
	cylinder.minimum = -height / 2.0;
	cylinder.maximum = height / 2.0;
	cylinder.closed = FALSE;
	return (cylinder);
}

t_vector	cylinder_normal_at(t_cylinder cyl, t_point point)
{
	t_vector	axis;
	t_point		projected;
	double		dist;

	dist = pow(point.x - cyl.center.x, 2) + pow(point.z - cyl.center.z, 2);
	if (dist < pow(cyl.radius, 2))
	{
		if (point.y >= cyl.maximum - EPSILON)
			return (create_vector(0, 1, 0));
		if (point.y <= cyl.minimum + EPSILON)
			return (create_vector(0, -1, 0));
	}
	axis = cyl.orientation;
	projected = add_tuples(cyl.center, scalar_mult_tuples(axis,
				dot_product(sub_tuples(point, cyl.center), axis)));
	return (normalize(sub_tuples(point, projected)));
}
