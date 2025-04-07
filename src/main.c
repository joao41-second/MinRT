/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/21 14:45:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light/light.h"
#include "matrix/matrix.h"
#include "minRT.h"
#include "ray/ray.h"
#include "ray/ray_struct.h"
#include "tuples/tuples.h"
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
	ray_set_transform(&sph,mat_gener_trans(0, 1,0) );
	ft_add_node(&sph,&word_objects );
	sph2 = sphere(create_point(0, 0.5, 0),1) ;
///	ray_set_transform(&sph2,mat_gener_scal(1, 1, 1) );
	ft_add_node(&sph2,&word_objects);	
	rt_struct.word = ft_node_start( word_objects); 
	

	t_vector new  =	lig_reflect(create_vector(1, -1, 0), create_vector(0, 1, 0));
	printf("vect %f %f %f \n" ,new.x,new.y,new.z);


	canva_inicializ(&rt_struct, WALL_X, WALL_Y,c_new(0, 0, 0));	
	return (status);

}
