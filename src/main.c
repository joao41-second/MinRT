/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:43:20 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/16 12:30:40 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix/matrix.h"
#include "minRT.h"

int	main(int ac, char **av, char **env)
{
	t_minirt	rt_struct;
	t_matrix	ok ;
	int			status;

	status = 0;
	(void)ac;
	(void)av;
	(void)env;
	ft_start_alloc();
	start_word(&rt_struct);
	ok = mat_gener_identity(4);
	rt_struct.point = create_point(0, 0,0);
	ok = lig_view_transform(rt_struct.point,
			create_point(0, 0, 0), create_vector(0, 1, 0));
	// rt_struct.camera = cm_init(WALL_X, WALL_Y, M_PI / 3, ok);
	// //mat_print(rt_struct.camera.inv_tranform_matrix);

	// rt_struct.cam = cm_ray_for_pixel(rt_struct.camera,
	// 		(double)WALL_X / 2, (double)WALL_Y / 2);
	rt_struct.rota_y = 0;
	rt_struct.rota_x = 0;

	rt_struct.needs_render = 4;
	camera_init(&rt_struct.camera, create_point(0, 1, -10), 
                       create_vector(0, 0, 1), 100.0);
	unified_camera_set_mode(&rt_struct.camera, CAM_MODE_J);
	
	canva_inicializ(&rt_struct, WALL_X, WALL_Y, c_new(0, 0, 0));
	return (status);
}
