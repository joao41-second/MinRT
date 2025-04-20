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
#include <math.h>

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

	t_point point = create_point(50,50,0);
	t_matrix mat2 = mat_gener_trans(-point.x, -point.y, -point.z);
	
	lig_view_transform(point, create_point(0,1,0), create_vector(0, 1, 0),&ok,mat2);

        rt_struct.cam_m = cm_init(400, 400, M_PI/2, ok);


	canva_inicializ(&rt_struct, WALL_X, WALL_Y,c_new(0, 0, 0));	
	mat_print(ok);
	 
	return (status);

}
