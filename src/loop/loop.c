/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/21 23:35:50 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"
#include "../minRT.h"
#include <stdio.h>
#include <time.h>

void	loop(t_minirt *rt_struct)
{
	char	*str;
	clock_t start;
	clock_t end;
	
		
	mat_set_view_transform(&rt_struct->cam_m.tranform_matrix, create_point(1, 1,-3), 
			create_point(0, 0, 0), create_vector(0, 1, 0));

	mat_set_rota(rt_struct->cam_m.calculate.rot_x, 'x', rt_struct->rota_x);
	mat_set_multip(&rt_struct->cam_m.tranform_matrix,rt_struct->cam_m.calculate.rot_x,mat_cp(rt_struct->cam_m.tranform_matrix));

	mat_set_multip(&rt_struct->cam_m.tranform_matrix,mat_cp(rt_struct->cam_m.tranform_matrix), mat_gener_rota('y', rt_struct->rota_y));
	mat_set_multip(&rt_struct->cam_m.tranform_matrix,mat_cp(rt_struct->cam_m.tranform_matrix),
			mat_gener_trans(rt_struct->point.x, rt_struct->point.y, rt_struct->point.z));

	//mat_set_multip(&rt_struct->cam_m.tranform_matrix,mat_gener_rota('z', 1.7),mat_cp(rt_struct->cam_m.tranform_matrix));


	start = clock();
	cm_update(&rt_struct->cam_m);
	cm_windo_put(rt_struct, WALL_X, WALL_Y,rt_struct->needs_render);
	end = clock();
	printf("time for gener the frame %f second\n",(double)1/((double)( (double)end -  (double)start)/ (double)CLOCKS_PER_SEC));
	 double vaule = ((double)( (double)end -  (double)start)/ (double)CLOCKS_PER_SEC) ;
	canva_update(rt_struct);
	asprintf(&str, "cord: %f %f %f  dir: %f %f %f",
		rt_struct->cam.origin.x, rt_struct->cam.origin.y,
		rt_struct->cam.origin.z, rt_struct->cam.direction.x,
		rt_struct->cam.direction.y, rt_struct->cam.direction.z);
	mlx_string_put(rt_struct->canva.mlx, rt_struct->canva.mlx_wind,
		10, 10, create_trgb( 255, 255, 2), str);
	asprintf(&str, "cord: %f %f %f ", rt_struct->luz.point.x,
		rt_struct->luz.point.y, rt_struct->luz.point.z);
	mlx_string_put(rt_struct->canva.mlx,
		rt_struct->canva.mlx_wind,
		20, 20, create_trgb( 255, 255, 2), str);

	mlx_string_put(rt_struct->canva.mlx,
		rt_struct->canva.mlx_wind,
		10, 30, create_trgb( 255, 255, 2), "fps :");	

	mlx_string_put(rt_struct->canva.mlx,
		rt_struct->canva.mlx_wind,
		50, 30, create_trgb( 255, 255, 2), ft_itoa(((double)1/vaule)));	


}
