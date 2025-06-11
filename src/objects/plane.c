/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:21:35 by rerodrig          #+#    #+#             */
/*   Updated: 2025/06/05 12:47:44 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

t_vector	plane_normal_at(t_plane *plane, t_point point)
{
	(void)plane;
	(void)point;
	return (create_vector(0, 1, 0));
}

t_plane	create_plane(t_point point1, t_point point2, t_point point3)
{
	t_plane		plane;
	t_vector	ab;
	t_vector	ac;

	plane.point1 = point1;
	plane.point2 = point2;
	plane.point3 = point3;
	ab = sub_tuples(plane.point2, plane.point1);
	ac = sub_tuples(plane.point3, plane.point1);
	plane.normal = cross_product(ab, ac);
	return (plane);
}

t_plane	create_plane_parser(t_point p, t_vector n)
{
	t_vector	up;
	t_vector	u;
	t_vector	v;
	t_point		p2;
	t_point		p3;

	if (fabs(n.x) > 0.9)
		up = create_vector(0, 1, 0);
	else
		up = create_vector(1, 0, 0);
	u = normalize(cross_product(up, n));
	v = cross_product(n, u);
	p2 = create_point(p.x + u.x, p.y + u.y, p.z + u.z);
	p3 = create_point(p.x + v.x, p.y + v.y, p.z + v.z);
	return (create_plane(p, p2, p3));
}
