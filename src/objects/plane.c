/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:21:35 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/05 02:49:15 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"


t_vector plane_normal_at(t_plane *plane, t_point point)
{
    (void)plane;
    (void)point;
    return create_vector(0, 1, 0);
}
t_vector local_normal_at_plane(t_object *plane, t_point point)
{
    t_vector world_normal = plane->u_data.plane.normal;

    (void)point;
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
    t_plane plane;

    plane.center = center;
    plane.ray_s = ray_s;
    plane.base_normal = create_vector(0, 1, 0); // Default normal
    plane.normal = plane.base_normal;
    plane.transform = mat_gener(4);
    plane.inv_transform = mat_gener(4);
    plane.inv_transpose = mat_gener(4);
    plane.matiral = obj_material_init(c_new(0,1,1), obj_init_values_material(0.1,0.6 , 0.3, 100));
    // Debugging: Print the initial transformation matrices
    printf("Plane Initial Transform:\n");
    mat_print(plane.transform);
    printf("Plane Initial Inverse Transform:\n");
    mat_print(plane.inv_transform);
    printf("Plane Initial Inverse Transpose:\n");
    mat_print(plane.inv_transpose);

    return plane;
}
