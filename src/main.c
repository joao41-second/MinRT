/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/21 14:45:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camara_m/camara_m.h"
#include "light/light.h"
#include "matrix/matrix.h"
#include "minRT.h"
#include "tuples/tuples.h"
#include <X11/X.h>
#include <math.h>
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_minirt	rt_struct;
	int			status;

	status = 0;
	(void)ac;
	(void)av;
	(void)env;

	ft_start_alloc();
    	rt_struct.needs_render = 1;
	start_word(&rt_struct);
	
	t_matrix ok ;

	ok = mat_gener_identity(4);

	//init camera
	t_point origin = create_point(0, 0, 10);
	t_vector direction = create_vector(0,  0, -1);
	double fov = 30.0;

	camera_init(&rt_struct.scene.world.camera, origin, direction, fov);

	rt_struct.point = create_point(0,0,2);

	ok = lig_view_transform(rt_struct.point, create_point(0,1,0), create_vector(0,1,0));

	ok = mat_multip( mat_gener_rota('x',0.054 * (180/M_PI)),ok);

        rt_struct.cam_m = cm_init( WALL_X ,WALL_Y , M_PI/2, ok);

	canva_inicializ(&rt_struct, WALL_X, WALL_Y,c_new(0, 0, 0));
	return (status);

}
