/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/15 14:51:33 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include <time.h>
#include "../camera/camera.h"

void	loop(t_minirt *rt_struct)
{

    	
// 	// clock_t inicio = clock();
// 	ray_canva( rt_struct);
// 	// clock_t fim = clock();
// 	// rt_struct->c_ray.direction = normalize(rt_struct->c_ray.direction);
//     // 	double tempo_exec = (double)(fim - inicio) / CLOCKS_PER_SEC; // Converte para segundos
// //    	printf("Tempo de execução: %.6f segundos\n", tempo_exec);
// 	draw_navigator(rt_struct);
//   	canva_update(rt_struct);
	// loop(rt_struct);
    static int ok = 0;

	// if(ok == 0)
	// {
	rt_struct->c_ray = ray_gener( create_point(0, 0, 0), create_vector(0, 0, 1));
	ft_pocket_new("canva");
	
	// Inlined implementation of ray_canva function
	    // clock_t inicio = clock();
		t_point point;
		double x;
        double y;
        double x_;
        double y_;
        t_tuple raiva;
        t_tuple sub;
        x = -1;
        y = -1;
		t_color color;
        // if (!rt_struct->needs_render)
        // return (1); 
        // rt_struct->needs_render = 0;
		while (++y < WALL_Y) 
		{
			x = -1;
			// y_ = (metade - y) * pix_size;
			while(++x < WALL_X)
			{
				// x_ = (-metade + x) * pix_size;
				// raiva = create_point(x_, y_, WALL_Z);
				// sub = sub_tuples(raiva, rt_struct->c_ray.direction);
				// t_obj_int intersections = ray_for_objects(rt_struct->word, ray_gener(point, normalize(sub)));
                t_ray ray = camera_generate_ray(&rt_struct->scene.world.camera, x, y);
                // Check for intersections with objects in the scene
                t_obj_int intersections = ray_for_objects(rt_struct->word, ray);
				if(intersections.min != INT_MAX)
				{
					// t_sphere *o = (t_sphere *) intersections.object;
					// t_sphere ok = *o;
					t_object *closest_obj = (t_object *)intersections.ints->content;
					point = ray_position(ray, intersections.min) ;
					if (closest_obj->type == OBJ_PLANE)
					{
						color = lig_lighting(closest_obj->u_data.plane.matiral, rt_struct->luz, 
							point,
							lig_normalize(closest_obj, point), // Pass closest_obj directly
							neg_tuple(ray.direction));
						canva_set_pixel(rt_struct, x, y, color);
					}
					else if (closest_obj->type == OBJ_SPHERE)
					{
						color = lig_lighting(closest_obj->u_data.sphere.matiral, rt_struct->luz, 
							point,
							lig_normalize(closest_obj, point), // Pass closest_obj directly
							neg_tuple(ray.direction));
						canva_set_pixel(rt_struct, x, y, color);
					}
					else
					{
						canva_set_pixel(rt_struct, x, y, c_new(255.0, 0, 0));
					}
		
					
					
				}
				else
				{
					canva_set_pixel(rt_struct, x, y, c_new(255.0, 255.0, 255.0));
				}
			}	
		}
	
        // clock_t fim = clock();
    	// double tempo_exec = (double)(fim - inicio) / CLOCKS_PER_SEC; // Converte para segundos
    	// printf("Tempo de execução: %.6f segundos\n", tempo_exec);
	
	ft_free_all_pocket("canva");
	// }
	// ok++;
	draw_navigator(rt_struct);
    
	canva_update(rt_struct);

};
