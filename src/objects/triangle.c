/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:13:56 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/21 21:10:09 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

t_triangle	create_triangle(t_point p1, t_point p2, t_point p3)
{
	t_triangle	triangle;

	triangle.p1 = p1;
	triangle.p2 = p2;
	triangle.p3 = p3;
	triangle.edge1 = sub_tuples(p2, p1);
	triangle.edge2 = sub_tuples(p3, p1);
	triangle.normal = normalize(cross_product(triangle.edge1, triangle.edge2));
	return (triangle);
}

//precomputed normal
t_vector	triangle_normal_at(t_triangle triangle)
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
