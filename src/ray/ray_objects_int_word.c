/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_int_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:31:53 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 19:53:40 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "ray.h"
#include "ray_struct.h"
#include <stdio.h>

// Add a forward declaration for check_cap at the top of the file

// At2+By+C=0
//
//A=dx2+dy2+dz2
//B=2[dx(px−cx)+dy(py−cy)+dz(pz−cz)]
//C=(px−cx)2+(py−cy)2+(pz−cz)2−R2
//
t_intersection	ray_int_sphere(t_ray ray, t_sphere shp)
{
	double			a_;
	double			b_;
	double			c_;
	double			temp;
	t_intersection	ret;

	a_ = ((ray.direction.x * ray.direction.x) + (ray.direction.y
				* ray.direction.y) + (ray.direction.z * ray.direction.z));
	b_ = 2 * ((ray.direction.x * (ray.origin.x - shp.center.x))
			+ (ray.direction.y * (ray.origin.y - shp.center.y))
			+ (ray.direction.z * (ray.origin.z - shp.center.z)));
	c_ = ((ray.origin.x - shp.center.x) * (ray.origin.x - shp.center.x))
		+ ((ray.origin.y - shp.center.y) * (ray.origin.y - shp.center.y))
		+ ((ray.origin.z - shp.center.z) * (ray.origin.z - shp.center.z))
		- (shp.ray_s * shp.ray_s);
	ret.object = &shp;
	ret.inter = (b_ * b_) - 4 * a_ * c_;
	if (ret.inter < EPSILON)
		return (ret);
	temp = sqrt(ret.inter);
	ret.t[1] = (-(b_) + temp) / (2 * a_);
	ret.t[0] = (-(b_) - temp) / (2 * a_);
	ret.ray_start = ray;
	return (ret);
}

t_intersection	ray_int_plane(t_ray ray, t_plane plane)
{
	t_intersection	ret;
	double			t;
	double			a;
	double			b;

	a = -(plane.normal.x * ray.origin.x + plane.normal.y
			* ray.origin.y + plane.normal.z * ray.origin.z);
	b = (plane.normal.x * ray.direction.x + plane.normal.y
			* ray.direction.y + plane.normal.z * ray.direction.z);
	t = (a / b);
	ret.inter = t;
	ret.t[0] = t;
	ret.t[1] = t;
	ret.object = &plane;
	return (ret);
}

t_intersection ray_in_trinagles(t_object *tri,int index,t_ray ray)
{
	int			i;
	int			i_;
	static	float		min;
	t_intersection		intr;
	t_intersection		min_;

	i = -1;
	min = (float)INT_MIN;
	min_.inter = 0;
	intr.t[0] = 0;
	while (++i < 12)
	{
		intr = ray_int_triangle(ray, tri->hit_box[i]);
		if (intr.t[0] > EPSILON)
		{
			i = 20;
			break ;
		}
	}
	if (i == 20)
	{
		i = -1;
		while (++i < index)
		{
			intr = ray_int_triangle(ray, tri->triangle[i]);
			if (min == INT_MIN && intr.t[0] > EPSILON)
			{
				min = 0;
				min_ = intr;
				tri->u_data.triangle = tri->triangle[i];
			}
			if (intr.t[0] > EPSILON && intr.t[0] < min_.t[0])
			{
				min_.t[0] = intr.t[0];
				min_.t[1] = intr.t[0];
				tri->u_data.triangle = tri->triangle[i];
				min_ = intr;
				i_ = i;
			}
		}
		return (min_);
	}
	return (intr);
}
