/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:13:56 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/08 17:18:27 by rerodrig         ###   ########.fr       */
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
    return (triangle);
}

t_vector triangle_normal_at(t_triangle triangle)
{
    //precomputed normal
    return (triangle.normal);
}

t_intersection ray_int_triangle(t_ray ray, t_object *obj)
{
    t_intersection ret;
    t_triangle *tri = &obj->u_data.triangle;
    
    // Transform the ray to object space
    t_ray transformed_ray = ray_transform(ray, tri->inv_transform);
    
    // Compute the determinant
    t_vector dir_cross_e2 = cross_product(tri->edge2, transformed_ray.direction);
    double det = dot_product(tri->edge1, dir_cross_e2);
    
    // If det is near zero, ray is parallel to triangle
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
    
    // Check if ray misses on the p1-p3 edge
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
    
    // Check if ray misses on p1-p2 or p2-p3 edges
    if (v < 0 || (u + v) > 1)
    {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    
    // Compute the intersection distance
    double t = f * dot_product(tri->edge2, origin_cross_e1);
    
    // Check if intersection is behind the ray
    if (t < 0)
    {
        ret.inter = 0;
        ret.t[0] = -1;
        ret.t[1] = -1;
        ret.object = NULL;
        return ret;
    }
    
    // Valid intersection found
    ret.inter = 1;
    ret.t[0] = t;
    ret.t[1] = -1; // Triangles have only one intersection
    ret.object = obj;
    
    return ret;
}