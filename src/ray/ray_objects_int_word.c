/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_int_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:31:53 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 16:33:20 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minRT.h"

// At2+By+C=0
//
//A=dx2+dy2+dz2
//B=2[dx(px−cx)+dy(py−cy)+dz(pz−cz)]
//C=(px−cx)2+(py−cy)2+(pz−cz)2−R2
//
t_intersection	ray_int_sphere(t_ray ray, t_sphere shp)
{
	t_intersection	ret;
	double			a_;
	double			b_;
	double			c_;
	double			temp;

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
	temp = sqrt(ret.inter);
	ret.t[1] = 0;
	ret.t[0] = 0;
	ret.t[1] += (-(b_) + temp) / (2 * a_);
	ret.t[0] += (-(b_) - temp) / (2 * a_);
	ret.ray_start = ray;
	return (ret);
}
