/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_int_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:31:53 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/13 20:25:16 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "ray.h"
#include "ray_struct.h"
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
    double t;
    double a;
    double b;
    t_intersection ret;

    a = -(plane.normal.x * ray.origin.x + plane.normal.y * ray.origin.y + plane.normal.z*ray.origin.z);
    b = (plane.normal.x*ray.direction.x + plane.normal.y * ray.direction.y + plane.normal.z*ray.direction.z);
    t = (a/b);
    ret.inter = t;
    ret.t[0] = t;
    ret.t[1] = t;
    ret.object = &plane;
    return ret;
}

t_intersection ray_in_trinagles(t_object *tri,int index,t_ray ray)
{
	int i;
	int i_;
static	float min;
	t_intersection intr;
	t_intersection min_;
	t_triangle tria;
	
	i = -1;
	min = INT_MAX;
	min_.inter = 0;
	while (++i < index)
	{

		intr = ray_int_triangle(ray, tri->triangle[i]);
		if(min == INT_MAX &&  intr.t[0] > EPSILON)
		{
			min = 0;
			min_ = intr;
			tri->u_data.triangle = tri->triangle[i];

		}
		if( intr.t[0] > EPSILON &&  intr.t[0] < min_.t[0] )
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

t_intersection ray_int_cylinder(t_ray ray, t_cylinder cylinder) {
    t_intersection intersection;
    intersection.t[0] = 0.0;
    intersection.t[1] = 0.0;
    double a, b, c, discriminant;
    double t1, t2;
    double y0, y1;
    intersection.inter = 0;
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
intersection.inter = 0;	
    return intersection;
}

static int check_cap(t_ray ray, double t, t_cylinder cylinder) {
    double x = ray.origin.x + t * ray.direction.x;
    double z = ray.origin.z + t * ray.direction.z;
    return (pow(x, 2) + pow(z, 2)) <= pow(cylinder.radius, 2);
}
