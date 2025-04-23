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
	t_list_ *word_objects;

	word_objects = NULL;
	status = 0;
	(void)ac;
	(void)av;
	(void)env;

	ft_start_alloc();
    	rt_struct.needs_render = 1;
	start_word(&rt_struct);
	
	//canva_inicializ(&rt_struct, WALL_X, WALL_Y,c_new(0, 0, 0));	
	t_matrix ok ;

	ok = mat_gener_identity(4);

	t_point point = create_point(-2,-2,1);
	ok = lig_view_transform(point, create_point(0,0,0), create_vector(0, 1,0));

        rt_struct.cam_m = cm_init( WALL_X ,WALL_Y , M_PI/2, ok);

	t_ray ray  =  cm_ray_for_pixel(rt_struct.cam_m, 200, 200);

	lig_print_tuple(ray.origin);
	
	printf("\n");

	lig_print_tuple(ray.direction);

	printf("\n");

	canva_inicializ(&rt_struct, WALL_X, WALL_Y,c_new(0, 0, 0));
	return (status);

}
