/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/21 14:45:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas/canvas_struct.h"
#include "light/light.h"
#include "matrix/matrix.h"
#include "minRT.h"
#include "tuples/tuples.h"
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
	t_sphere sph;
	t_sphere sph2;
	t_obj_int intr_in_objc;
	sph = sphere(create_point(0, 0, 0),1) ;
	//ray_set_transform(&sph,mat_multip(mat_gener_scal(1, 0.5, 1), mat_gener_rota('Z',(M_PI/5 ))));
	ray_set_transform(&sph,mat_gener_trans(0, 1, 0));
	ft_add_node(&sph,&word_objects );
	//sph2 = sphere(create_point(0, 1.5, 0),0.1) ;
	//ray_set_transform(&sph2,mat_gener_scal(1, 1, 1) );
	//ft_add_node(&sph2,&word_objects);	
	
	rt_struct.word = ft_node_start( word_objects); 

	t_light ok;

	rt_struct.luz = ligth_init(c_new(1,1,1), create_point(0, 2, 0));
	
	mat_print(sph.transform);
	//t_vector vetc = lig_normalize(sph, create_point(0, M_SQRT2 / 2, -(M_SQRT2/2)));

	t_vector vetc = lig_normalize(sph, create_point(0, 1.70711, -0.70711));
	printf("vect norm %f %f %f \n", vetc.val[0],vetc.val[1],vetc.val[2]);
 


//	canva_inicializ(&rt_struct, WALL_X, WALL_Y,c_new(0, 0, 0));	
	return (status);

}
