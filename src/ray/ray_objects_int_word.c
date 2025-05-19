/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_int_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:31:53 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/19 14:48:56 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include <stdio.h>

// Add a forward declaration for check_cap at the top of the file
static int check_cap(t_ray ray, double t, t_cylinder cylinder);

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

	ret.t[1] = -1;
	ret.t[0] = -1;
	if(ret.inter <  EPSILON)
		return (ret);
			
	temp = sqrt(ret.inter);
	ret.t[1] = (-(b_) + temp) / (2 * a_);
	ret.t[0] = (-(b_) - temp) / (2 * a_);
	ret.ray_start = ray;
	return (ret);


}
t_intersection ray_int_plane(t_ray ray, t_plane plane)
{
    t_intersection ret;
    double t;
    double a;
    double b;

    a = -(plane.normal.x * ray.origin.x + plane.normal.y * ray.origin.y + plane.normal.z*ray.origin.z);
    b = (plane.normal.x*ray.direction.x + plane.normal.y * ray.direction.y + plane.normal.z*ray.direction.z);
    t = (a/b);
    ret.inter = t;
    ret.t[0] = t;
    ret.t[1] = t;
    ret.object = &plane;
    return ret;
}

t_intersection ray_int_triangle(t_ray ray, t_object tri)
{
    t_intersection ret;
    t_vector dir_cross_e2 = cross_product(ray.direction, tri.u_data.triangle.edge2);
    double det = dot_product(tri.u_data.triangle.edge1, dir_cross_e2);
    if (fabs(det) < EPSILON) {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    double f = 1.0 / det;
    t_vector p1_to_origin = sub_tuples(ray.origin, tri.u_data.triangle.p1);
    double u = f * dot_product(p1_to_origin, dir_cross_e2);
    if (u < 0 || u > 1) {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    t_vector origin_cross_e1 = cross_product(p1_to_origin, tri.u_data.triangle.edge1);
    double v = f * dot_product(ray.direction, origin_cross_e1);
    if (v < 0 || (u + v) > 1) {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    double t = f * dot_product(tri.u_data.triangle.edge2, origin_cross_e1);
    if (t < 0) {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    ret.inter = 1;
    ret.t[0] = t;
    ret.t[1] = t;
    ret.object = &tri;
    return ret;
}


t_intersection ray_int_cylinder(t_ray ray, t_cylinder cylinder) {
    t_intersection intersection;
    intersection.t[0] = 0.0;
    intersection.t[1] = 0.0;
    double a, b, c, discriminant;
    double t1, t2;
    double y0, y1;
    intersection.inter = 0;

    a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
    b = 2 * (ray.origin.x * ray.direction.x + ray.origin.z * ray.direction.z);
    c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - pow(cylinder.radius, 2);

    discriminant = pow(b, 2) - 4 * a * c;
    if (fabs(a) < EPSILON || discriminant < 0) {
        return intersection;
    }

    t1 = (-b - sqrt(discriminant)) / (2 * a);
    t2 = (-b + sqrt(discriminant)) / (2 * a);

    if (t1 > t2) {
        double temp = t1;
        t1 = t2;
        t2 = temp;
    }

    y0 = ray.origin.y + t1 * ray.direction.y;
    y1 = ray.origin.y + t2 * ray.direction.y;
    if (cylinder.minimum < y0 && y0 < cylinder.maximum) {
        intersection.t[(int)intersection.inter++] = t1;
    }
    if (cylinder.minimum < y1 && y1 < cylinder.maximum) {
        intersection.t[(int)intersection.inter++] = t2;
    }

    if (cylinder.closed && fabs(ray.direction.y) > EPSILON) {
        double t_cap;

        t_cap = (cylinder.minimum - ray.origin.y) / ray.direction.y;
        if (check_cap(ray, t_cap, cylinder)) {
            intersection.t[(int)intersection.inter++] = t_cap;
        }

        t_cap = (cylinder.maximum - ray.origin.y) / ray.direction.y;
        if (check_cap(ray, t_cap, cylinder)) {
            intersection.t[(int)intersection.inter++] = t_cap;
        }
    }

    return intersection;
}

static int check_cap(t_ray ray, double t, t_cylinder cylinder) {
    double x = ray.origin.x + t * ray.direction.x;
    double z = ray.origin.z + t * ray.direction.z;
    return (pow(x, 2) + pow(z, 2)) <= pow(cylinder.radius, 2);
}
