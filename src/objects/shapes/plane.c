/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:21:35 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/08 15:11:19 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"

t_vector plane_normal_at(t_plane *plane, t_point point)
{
    (void)plane;
    (void)point;
    return create_vector(0, 1, 0);
}

t_vector local_intersect_plane(t_object *plane, t_ray ray)
{
    double      t;
    t_vector    normal;

    if (fabs(ray.direction.y) < EPSILON)
        return (create_vector(0, 0, 0));
    t = (plane->u_data.plane.center.y - ray.origin.y) / ray.direction.y;
    normal = plane_normal_at(&plane->u_data.plane, ray.origin);
    return (scalar_mult_tuples(normal, t));
}
t_plane create_plane(t_point center, double ray_s)
{
    t_plane plane;

    plane.center = center;
    plane.ray_s = ray_s;
    plane.normal = plane_normal_at(&plane, center);
    return (plane);
}
