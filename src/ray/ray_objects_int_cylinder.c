/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_int_cylinder.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:31:53 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 11:43:53 by rerodrig         ###   ########.fr       */
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

static int	check_cap(t_ray ray, double t, t_cylinder cylinder)
{
	double	x;
	double	z;

	x = ray.o.x + t * ray.d.x;
	z = ray.o.z + t * ray.d.z;
	return ((pow(x, 2) + pow(z, 2)) <= pow(cylinder.radius, 2));
}

static void	swap_values(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	check_caps(t_ray ray, t_cylinder cyl, t_intersection *intersection)
{
	double	t_cap;

	if (cyl.closed && fabs(ray.d.y) > EPSILON)
	{
		t_cap = (cyl.minimum - ray.o.y) / ray.d.y;
		if (check_cap(ray, t_cap, cyl))
			intersection->t[(int)intersection->inter++] = t_cap;
		t_cap = (cyl.maximum - ray.o.y) / ray.d.y;
		if (check_cap(ray, t_cap, cyl))
			intersection->t[(int)intersection->inter++] = t_cap;
	}
}

t_intersection	ray_int_cylinder(t_ray ray, t_cylinder cylinder)
{
	t_intersection	intersection;
	double			abc[3];
	double			discriminant;
	double			t1_t2[2];
	double			y0_y1[2];

	intersection = init_intersection();
	abc[0] = pow(ray.d.x, 2) + pow(ray.d.z, 2);
	abc[1] = 2 * (ray.o.x * ray.d.x + ray.o.z * ray.d.z);
	abc[2] = pow(ray.o.x, 2) + pow(ray.o.z, 2) - pow(cylinder.radius, 2);
	discriminant = pow(abc[1], 2) - 4 * abc[0] * abc[2];
	if (fabs(abc[0]) < EPSILON || discriminant < 0)
		return (intersection);
	t1_t2[0] = (-abc[1] - sqrt(discriminant)) / (2 * abc[0]);
	t1_t2[1] = (-abc[1] + sqrt(discriminant)) / (2 * abc[0]);
	if (t1_t2[0] > t1_t2[1])
		swap_values(&t1_t2[0], &t1_t2[1]);
	y0_y1[0] = ray.o.y + t1_t2[0] * ray.d.y;
	y0_y1[1] = ray.o.y + t1_t2[1] * ray.d.y;
	if (cylinder.minimum < y0_y1[0] && y0_y1[0] < cylinder.maximum)
		intersection.t[(int)intersection.inter++] = t1_t2[0];
	if (cylinder.minimum < y0_y1[1] && y0_y1[1] < cylinder.maximum)
		intersection.t[(int)intersection.inter++] = t1_t2[1];
	check_caps(ray, cylinder, &intersection);
	return (intersection);
}
