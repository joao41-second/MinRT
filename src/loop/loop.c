/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 12:46:12 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"
#include "../minRT.h"
#include <stdio.h>
#include <time.h>


void	loop(t_minirt *rt_struct)
{

    	
//	clock_t inicio = clock();
//	ray_canva( rt_struct);
//	clock_t fim = clock();
//	rt_struct->c_ray.direction = normalize(rt_struct->c_ray.direction);
 //   	double tempo_exec = (double)(fim - inicio) / CLOCKS_PER_SEC; // Converte para segundos
//    	printf("Tempo de execução: %.6f segundos\n", tempo_exec);
		
//mouse(rt_struct)	;
	cm_windo_put(rt_struct, WALL_X ,  WALL_Y );

  		canva_update(rt_struct);
		draw_navigator(rt_struct);
		draw_cube_labels(rt_struct);
		char *str;
	

		asprintf(&str, "cam cord: %f %f %f  dir: %f %f %f",rt_struct->scene.world.camera.origin.x,rt_struct->scene.world.camera.origin.y,rt_struct->scene.world.camera.origin.z,rt_struct->scene.world.camera.direction.x,rt_struct->scene.world.camera.direction.y,rt_struct->scene.world.camera.direction.z);

		mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, 10, 10,create_trgb(1, 255, 255, 2), str);
	asprintf(&str, "cord: %f %f %f ",rt_struct->luz.point.x,rt_struct->luz.point.y,rt_struct->luz.point.z);


		mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, 20, 20,create_trgb(1, 255, 255, 2), str);


};
