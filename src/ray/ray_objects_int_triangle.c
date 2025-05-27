/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_int_triangle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:31:53 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 11:44:25 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include <stdio.h>

static t_intersection	init_intersection(void)
{
	t_intersection	ret;

	ret.inter = 0;
	ret.t[0] = -1;
	ret.t[1] = -1;
	ret.object = NULL;
	return (ret);
}

static int	check_triangle_bounds(double u, double v)
{
	return (u >= 0 && u <= 1 && v >= 0 && (u + v) <= 1);
}

//double		fuv[3]; // f, u, and v combined
static int	calculate_triangle_intersection(t_ray ray, t_triangle tri, double *t)
{
	t_vector	dir_cross_e2;
	t_vector	p1_to_origin;
	t_vector	origin_cross_e1;
	double		fuv[3];

	dir_cross_e2 = cross_product(ray.direction, tri.edge2);
	fuv[0] = dot_product(tri.edge1, dir_cross_e2);
	if (fabs(fuv[0]) < EPSILON)
		return (0);
	fuv[0] = 1.0 / fuv[0];
	p1_to_origin = sub_tuples(ray.origin, tri.p1);
	fuv[1] = fuv[0] * dot_product(p1_to_origin, dir_cross_e2);
	if (!check_triangle_bounds(fuv[1], 0))
		return (0);
	origin_cross_e1 = cross_product(p1_to_origin, tri.edge1);
	fuv[2] = fuv[0] * dot_product(ray.direction, origin_cross_e1);
	if (!check_triangle_bounds(fuv[1], fuv[2]))
		return (0);
	*t = fuv[0] * dot_product(tri.edge2, origin_cross_e1);
	return (*t >= 0);
}

t_intersection	ray_int_triangle(t_ray ray, t_triangle tri)
{
	t_intersection	ret;
	double			t;

	ret = init_intersection();
	if (!calculate_triangle_intersection(ray, tri, &t))
		return (ret);
	ret.inter = 1;
	ret.t[0] = t;
	ret.t[1] = t;
	ret.object = &tri;
	return (ret);
}
