/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_int_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:12:32 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 02:35:37 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

// At2+By+C=0
//
//A=dx2+dy2+dz2
//B=2[dx(px−cx)+dy(py−cy)+dz(pz−cz)]
//C=(px−cx)2+(py−cy)2+(pz−cz)2−R2
//
t_intersection ray_int_sphere(t_ray ray_,t_sphere shp)
{
	t_intersection ret;
	double a_;
	double b_;
	double c_;
	double temp;
	t_ray ray;

	ray = ray_transform(ray_,shp.inv_transform);	   
	a_ = ((ray.direction.x * ray.direction.x) + (ray.direction.y * ray.direction.y )+ (ray.direction.z * ray.direction.z)) ;

	b_ = 2 * ((ray.direction.x * (ray.origin.x - shp.center.x)) +
			(ray.direction.y * (ray.origin.y - shp.center.y)) +
				(ray.direction.z * (ray.origin.z - shp.center.z)));
	c_ = ((ray.origin.x - shp.center.x)*(ray.origin.x - shp.center.x)) +
		((ray.origin.y - shp.center.y)*(ray.origin.y - shp.center.y)) +
			((ray.origin.z - shp.center.z)*(ray.origin.z - shp.center.z))
				- (shp.ray_s * shp.ray_s);
	ret.object = &shp;
	ret.inter = (b_*b_) -4 * a_ * c_;
	temp = sqrt(ret.inter);	
	ret.t[1] = 0;
	ret.t[0] = 0;
	ret.t[1] += (-(b_) + temp)/(2 * a_);
	ret.t[0] += (-(b_) - temp)/(2 * a_);
	ret.ray_start = ray;
	return(ret);
}

t_intersection ray_int_plane(t_ray ray, t_plane *plane)
{
    t_intersection ret;
    double denom = dot_product(plane->normal, ray.direction);

    if (fabs(denom) < EPSILON)
    {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }

    double t = dot_product(plane->normal, sub_tuples(plane->center, ray.origin)) / denom;
    if (t < 0)
    {
        // Intersection is behind the ray origin
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }

    ret.inter = 1;
    ret.t[0] = t;
    ret.t[1] = -1;
    ret.object = &plane;
        // Debugging: Print intersection details
        // printf("Plane Intersection: t = %f, Normal = (%f, %f, %f)\n",
        //     t, plane->normal.x, plane->normal.y, plane->normal.z);
    return ret;
}

t_intersection ray_int_triangle(t_ray ray, t_triangle *tri)
{
    t_intersection ret;
    // t_triangle *tri = &obj->u_data.triangle;
    t_ray transformed_ray = ray_transform(ray, tri->inv_transform);
    t_vector dir_cross_e2 = cross_product(tri->edge2, transformed_ray.direction);
    double det = dot_product(tri->edge1, dir_cross_e2);
    if (fabs(det) < EPSILON)
    {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    double f = 1.0 / det;
    t_vector p1_to_origin = sub_tuples(transformed_ray.origin, tri->p1);
    double u = f * dot_product(p1_to_origin, dir_cross_e2);
    if (u < 0 || u > 1)
    {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    t_tuple origin_cross_e1 = cross_product(p1_to_origin, tri->edge1);
    double v = f * dot_product(transformed_ray.direction, origin_cross_e1);
    if (v < 0 || (u + v) > 1)
    {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    double t = f * dot_product(tri->edge2, origin_cross_e1);
    if (t < 0)
    {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    ret.inter = 1;
    ret.t[0] = t;
    ret.t[1] = -1;
    ret.object = &tri;
    return ret;
}