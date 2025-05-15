/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:21:35 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/07 11:13:05 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

t_vector plane_normal_at(t_plane *plane, t_point point)
{
    (void)plane;
    (void)point;
    return create_vector(0, 1, 0);
}
// t_vector local_normal_at_plane(t_object *plane, t_point point)
// {
//     t_vector world_normal = plane->u_data.plane.normal;

//     (void)point;
//     t_vector object_normal = mat_x_tuple(world_normal, plane->u_data.plane.inv_transform);
//     t_vector world_normal_final = mat_x_tuple(object_normal, plane->u_data.plane.transform);
    
//     return world_normal_final;
// }
/*
t_vector local_intersect_plane(t_object *plane, t_ray ray)
{
    double t;
    t_vector normal;


    if (fabs(ray.direction.y) < EPSILON)
        return (create_vector(0, 0, 0));

    t = (plane->u_data.plane.center.y - ray.origin.y) / ray.direction.y;
    normal = plane_normal_at(&plane->u_data.plane, ray.origin);
    return (scalar_mult_tuples(normal, t));
}*/

t_plane create_plane(t_point point1,t_point point2 ,t_point point3)
{
    t_plane plane;
    t_vector ab;
    t_vector ac;

    plane.point1 = point1;
    plane.point2 = point2;
    plane.point3 = point3;
    ab = sub_tuples(plane.point2, plane.point1); 
    ac = sub_tuples(plane.point3, plane.point1);	
    plane.normal = cross_product(ab, ac);
//    plane.normal= normalize(plane.normal);
    return plane;
}
