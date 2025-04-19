/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/19 11:07:05 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include <time.h>
#include "../camera/camera.h"

void	loop(t_minirt *rt_struct)
{
    static int ok = 0;
    rt_struct->c_ray = ray_gener(create_point(0, 0, 0), create_vector(0, 0, 1));
    ft_pocket_new("canva");

    t_point point;
    double x, y;
    t_color color;

    y = -1;
    while (++y < WALL_Y)
    {
        x = -1;
        while (++x < WALL_X)
        {
            t_ray ray = camera_generate_ray(&rt_struct->scene.world.camera, x, y);
            t_obj_int intersections = ray_for_objects(rt_struct->word, ray);

            if (intersections.min != INT_MAX)
            {
                t_object *closest_obj = (t_object *)intersections.ints->content;
                point = ray_position(ray, intersections.min);

                // printf("Debug: Closest object type = %d, Intersection point = (%f, %f, %f)\n",
                    //    closest_obj->type, point.x, point.y, point.z);

                if (closest_obj->type == OBJ_PLANE)
                {
                    color = closest_obj->u_data.plane.matiral.color;
                }
                else if (closest_obj->type == OBJ_SPHERE)
                {
                    color = closest_obj->u_data.sphere.matiral.color;
                }
                else if (closest_obj->type == OBJ_TRIANGLE)
                {
                    color = closest_obj->u_data.triangle.matiral.color;
                }
                else
                {
                    color = c_new(1.0, 0.0, 0.0); // Unknown object type
                }

                // printf("Debug: Assigned color = (%f, %f, %f)\n", color.red, color.green, color.blue);
                canva_set_pixel(rt_struct, x, y, color);
            }
            else
            {
                // printf("Debug: No intersection at pixel (%f, %f)\n", x, y);
                canva_set_pixel(rt_struct, x, y, c_new(0.0, 0.0, 0.0));
            }
        }
    }

    ft_free_all_pocket("canva");
    draw_navigator(rt_struct);
    canva_update(rt_struct);
    draw_cube_labels(rt_struct);
}
