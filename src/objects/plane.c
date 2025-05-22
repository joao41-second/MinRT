/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:21:35 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/21 20:59:26 by rerodrig         ###   ########.fr       */
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
