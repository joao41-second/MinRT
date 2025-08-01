/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_int_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:31:53 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/17 18:46:31 by rerodrig         ###   ########.fr       */
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

	a_ = ((ray.dir.x * ray.dir.x) + (ray.dir.y
				* ray.dir.y) + (ray.dir.z * ray.dir.z));
	b_ = 2 * ((ray.dir.x * (ray.origin.x - shp.center.x))
			+ (ray.dir.y * (ray.origin.y - shp.center.y))
			+ (ray.dir.z * (ray.origin.z - shp.center.z)));
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
	b = (plane.normal.x * ray.dir.x + plane.normal.y
			* ray.dir.y + plane.normal.z * ray.dir.z);
	t = (a / b);
	ret.inter = t;
	ret.t[0] = t;
	ret.t[1] = t;
	ret.object = &plane;
	return (ret);
}

int	ray_chek_in_hit_box(t_object *tri, t_ray ray)
{
	t_intersection		intr;
	int					i;

	i = -1;
	while (++i < 12)
	{
		intr = ray_int_triangle(ray, tri->hit_box[i]);
		if (intr.t[0] > EPSILON)
		{
			return (1);
		}
	}
	return (0);
}

t_intersection	ray_in_trinagles(t_object *tri, int index, t_ray ray)
{
	const int		i_ = ray_chek_in_hit_box(tri, ray);
	int				min;
	int				i;
	t_intersection	intr;
	t_intersection	min_;

	min = INT_MIN;
	min_.inter = 0;
	min_.t[0] = -1;
	intr.t[0] = 0;
	i = -1;
	while (i_ == 1 && ++i < index)
	{
		intr = ray_int_triangle(ray, tri->triangle[i]);
		if ((intr.t[0] > EPSILON && intr.t[0] < min_.t[0])
			|| (min == INT_MIN && intr.t[0] > EPSILON && min))
		{
			min = 0;
			tri->u_data.triangle = tri->triangle[i];
			min_ = intr;
		}
	}
	return (min_);
}
