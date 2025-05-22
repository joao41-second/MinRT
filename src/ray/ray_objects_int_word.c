/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_int_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:31:53 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 11:41:49 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include <stdio.h>

t_intersection	ray_int_sphere(t_ray ray, t_sphere shp)
{
	t_intersection	ret;
	double			a_;
	double			b;
	double			c_;
	double			temp;

	a_ = ((ray.d.x * ray.d.x) + (ray.d.y
				* ray.d.y) + (ray.d.z * ray.d.z));
	b = 2 * ((ray.d.x * (ray.o.x - shp.center.x)) + (ray.d.y * (ray.o.y
					- shp.center.y)) + (ray.d.z * (ray.o.z - shp.center.z)));
	c_ = ((ray.o.x - shp.center.x) * (ray.o.x - shp.center.x))
		+ ((ray.o.y - shp.center.y) * (ray.o.y - shp.center.y))
		+ ((ray.o.z - shp.center.z) * (ray.o.z - shp.center.z))
		- (shp.ray_s * shp.ray_s);
	ret.object = &shp;
	ret.inter = (b * b) - 4 * a_ * c_;
	ret.t[1] = -1;
	ret.t[0] = -1;
	if (ret.inter < EPSILON)
		return (ret);
	temp = sqrt(ret.inter);
	ret.t[1] = (-(b) + temp) / (2 * a_);
	ret.t[0] = (-(b) - temp) / (2 * a_);
	ret.ray_start = ray;
	return (ret);
}

t_intersection	ray_int_plane(t_ray ray, t_plane plane)
{
	t_intersection	ret;
	double			t;
	double			a;
	double			b;

	a = -(plane.normal.x * ray.o.x + plane.normal.y * ray.o.y
			+ plane.normal.z * ray.o.z);
	b = (plane.normal.x * ray.d.x + plane.normal.y * ray.d.y
			+ plane.normal.z * ray.d.z);
	t = (a / b);
	ret.inter = t;
	ret.t[0] = t;
	ret.t[1] = t;
	ret.object = &plane;
	return (ret);
}
