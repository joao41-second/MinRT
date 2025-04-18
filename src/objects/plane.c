/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:21:35 by rerodrig          #+#    #+#             */
/*   Updated: 2025/04/04 19:54:17 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"


t_vector plane_normal_at(t_plane *plane, t_point point)
{
    (void)plane;
    return create_vector(0, 1, 0);
}
t_vector local_normal_at_plane(t_object *plane, t_point point)
{
    t_vector world_normal = plane->u_data.plane.normal;
    t_vector object_normal = mat_x_tuple(world_normal, plane->u_data.plane.inv_transform);
    t_vector world_normal_final = mat_x_tuple(object_normal, plane->u_data.plane.transform);
    
    return world_normal_final;
}

t_vector local_intersect_plane(t_object *plane, t_ray ray)
{
    double t;
    t_vector normal;

    if (fabs(ray.direction.y) < EPSILON)
        return (create_vector(0, 0, 0));

    t = (plane->u_data.plane.center.y - ray.origin.y) / ray.direction.y;
    normal = plane_normal_at(&plane->u_data.plane, ray.origin);
    return (scalar_mult_tuples(normal, t));
}
t_plane create_plane(t_point center, double ray_s)
{
    t_plane new;

    new.center = center;
    new.ray_s = ray_s;
    new.normal = create_vector(0, 1, 0);
    new.color = c_new(255, 0, 0);
    new.transform = mat_gener(4);
    new.inv_transform = mat_gener(4);
    new.matiral = obj_material_init(c_new(1,0.2,1), obj_init_values_material(0.1,0.9 , 0.9, 200));
    
    return (new);
}
