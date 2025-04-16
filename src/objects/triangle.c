/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:13:56 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/16 12:57:20 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minRT.h"
t_triangle create_triangle(t_point p1, t_point p2, t_point p3)
{
    t_triangle triangle;
    triangle.p1 = p1;
    triangle.p2 = p2;
    triangle.p3 = p3;
    triangle.edge1 = sub_tuples(p2, p1);
    triangle.edge2 = sub_tuples(p3, p1);
    triangle.normal = normalize(cross_product(triangle.edge1, triangle.edge2));
    triangle.transform = mat_gener_identity(4);
    triangle.inv_transform = mat_gener_identity(4);
    triangle.matiral = obj_material_init(c_new(1,0.2,1), obj_init_values_material(0.1,0.9 , 0.9, 200));
    return (triangle);
}
//precomputed normal
t_vector triangle_normal_at(t_triangle triangle)
{
    return (triangle.normal);
}
// Transform the ray to object space
// Compute the determinant
// If det is near zero, ray is parallel to triangle
// Check if ray misses on the p1-p3 edge
// Check if ray misses on p1-p2 or p2-p3 edges
// Compute the intersection distance
// Check if intersection is behind the ray
// Valid intersection found
t_intersection ray_int_triangle(t_ray ray, t_object *obj)
{
    t_intersection ret;
    t_triangle *tri = &obj->u_data.triangle;
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
    ret.t[1] = -1; // Triangles have only one intersection
    ret.object = obj;
    return ret;
}