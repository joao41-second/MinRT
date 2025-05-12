/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/12 14:10:40 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"
#include "../minRT.h"

void	loop(t_minirt *rt_struct)
{
	char	*str;

	cm_windo_put(rt_struct, WALL_X, WALL_Y, 2);
	canva_update(rt_struct);
	draw_navigator(rt_struct);
	draw_cube_labels(rt_struct);
	// asprintf(&str, "cord: %f %f %f  dir: %f %f %f",
	// 	rt_struct->cam.origin.x, rt_struct->cam.origin.y,
	// 	rt_struct->cam.origin.z, rt_struct->cam.direction.x,
	// 	rt_struct->cam.direction.y, rt_struct->cam.direction.z);
	// mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind,
	// 	10, 10, create_trgb(1, 255, 255, 2), str);
	// asprintf(&str, "cord: %f %f %f ", rt_struct->luz.point.x,
	// 	rt_struct->luz.point.y, rt_struct->luz.point.z);
	// mlx_string_put(rt_struct->canva.mlx,
	// 	rt_struct->canva.mlx_wind,
	// 	20, 20, create_trgb(1, 255, 255, 2), str);
	asprintf(&str, "camera mode: %s", 
		(rt_struct->camera.mode == CAM_MODE_R) ? "Camera Rei" : "Camera Joao");
	mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, 10, 30, create_trgb(1, 255, 255, 2), str);
	asprintf(&str, "cam cord: %f %f %f  dir: %f %f %f",rt_struct->camera.origin.x,rt_struct->camera.origin.y,rt_struct->camera.origin.z,rt_struct->camera.direction.x,rt_struct->camera.direction.y,rt_struct->camera.direction.z);

		mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, 10, 10,create_trgb(1, 255, 255, 2), str);
	asprintf(&str, "luz cord: %f %f %f ",rt_struct->luz.point.x,rt_struct->luz.point.y,rt_struct->luz.point.z);


		mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, 20, 20,create_trgb(1, 255, 255, 2), str);

}
