/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_int_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2025/05/05 16:31:53 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/07 12:02:08 by rerodrig         ###   ########.fr       */
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
	// ret.object = &shp;
	ret.inter = (b_ * b_) - 4 * a_ * c_;
	temp = sqrt(ret.inter);
	ret.t[1] = 0;
	ret.t[0] = 0;
	ret.t[1] += (-(b_) + temp) / (2 * a_);
	ret.t[0] += (-(b_) - temp) / (2 * a_);
	ret.ray_start = ray;
	return (ret);
}
// Ray equation: P(t) = O + t * D
//  N • (P - P0) = 0
// N • (O + t * D - P0) = 0
// t = (N • (P0 - O)) / (N • D)
// Where:
// - N is the normal vector of the plane
// - P0 is a point on the plane
// - O is the ray origin
// - D is the ray direction
// - t is the distance from the ray origin to the intersection point
t_intersection ray_int_plane(t_ray ray, t_plane plane)
{
    t_intersection  ret;
    double          denom;

    denom = dot_product(plane.normal, ray.direction);
    if (fabs(denom) < EPSILON)
    {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    double t = dot_product(plane.normal, sub_tuples(plane.center, ray.origin)) / denom;
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
    return (ret);
}

// ---->edges
// edge1 = P2 - P1
// edge2 = P3 - P1
// ---->determinant
// h = D × edge2
// det = edge1 • h
// If |det| < EPSILON,  ray parallel to triangle
// ---->barycentric coordinates
// f = 1 / det
// s = O - P1
// u = f * (s • h)
// If u < 0 or u > 1,intersection outside of triangle
// q = s × edge1
// v = f * (D • q)
// If v < 0 or u + v > 1, intersection outside of triangle
// ---->intersection distance t
// t = f * (edge2 • q)
// If t < 0, intersection is behind the ray origin
// If all conditions are satisfied, the ray intersects the triangle
t_intersection ray_int_triangle(t_ray ray, t_object obj)
{
    t_intersection  ret;
    t_ray           transformed_ray;
    t_vector        dir_cross_e2;
    t_vector        p1_to_origin;
    t_tuple         origin_cross_e1;
    double det;
    double f;
    double u;
    double v;
    double t;

    transformed_ray = ray_transform(ray, obj.inv_transform);
    dir_cross_e2 = cross_product(obj.u_data.triangle.edge2, transformed_ray.direction);
    det = dot_product(obj.u_data.triangle.edge1, dir_cross_e2);
    if (fabs(det) < EPSILON)
    {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    f = 1.0 / det;
    p1_to_origin = sub_tuples(transformed_ray.origin, obj.u_data.triangle.p1);
    u = f * dot_product(p1_to_origin, dir_cross_e2);
    if (u < 0 || u > 1)
    {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    origin_cross_e1 = cross_product(p1_to_origin, obj.u_data.triangle.edge1);
    v = f * dot_product(transformed_ray.direction, origin_cross_e1);
    if (v < 0 || (u + v) > 1)
    {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    t = f * dot_product(obj.u_data.triangle.edge2, origin_cross_e1);
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
    ret.object = &obj;
    // printf("Debug: det: %f, u: %f, v: %f, t: %f\n", det, u, v, t);
    // printf("Debug: Triangle edges: edge1(%f, %f, %f), edge2(%f, %f, %f)\n", obj.u_data.triangle.edge1.x, obj.u_data.triangle.edge1.y, obj.u_data.triangle.edge1.z, obj.u_data.triangle.edge2.x, obj.u_data.triangle.edge2.y, obj.u_data.triangle.edge2.z);
    // printf("Debug: Ray origin: (%f, %f, %f), direction: (%f, %f, %f)\n", transformed_ray.origin.x, transformed_ray.origin.y, transformed_ray.origin.z, transformed_ray.direction.x, transformed_ray.direction.y, transformed_ray.direction.z);
    return ret;
}

// Cylinder  x² + z² = r² (infinite cylinder along the y-axis)
// (Ox + t * Dx)² + (Oz + t * Dz)² = r²
// A * t² + B * t + C = 0
//
// A = Dx² + Dz²
// B = 2 * (Ox * Dx + Oz * Dz)
// C = Ox² + Oz² - r²
// t = (-B ± √(B² - 4AC)) / (2A)
// - Check if the intersection points are within the cylinder's height:
//   y0 = Oy + t1 * Dy
//   y1 = Oy + t2 * Dy
//   If y0 or y1 is outside [cylinder.minimum, cylinder.maximum], discard the intersection
t_intersection ray_int_cylinder(t_ray ray, t_cylinder cylinder) 
{
    t_intersection intersection;
    double a, b, c, discriminant;
    double t1, t2;
    double y0, y1;

    intersection.inter = 0;
    intersection.inter = 0;
    intersection.t[0] = 0.0;
    intersection.t[1] = 0.0;
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
    return (intersection);
}

