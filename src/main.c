/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/21 14:45:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix/matrix.h"
#include "minRT.h"
#include "ray/ray.h"
#include "ray/ray_struct.h"
#include "tuples/tuples.h"

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
	ft_add_node(&sph,&word_objects );
//	sph2 = sphere(create_point(0, 0, 10),1) ;
///	ft_add_node(&sph2,&word_objects);	
	rt_struct.word = word_objects;

	t_ray test = ray_gener(create_point(1, 2, 3), create_vector(0,1,0) );
	t_matrix scal = mat_gener_scal(2, 3,4 );
	t_ray final = ray_gener(mat_x_tuple(test.origin, scal), mat_x_tuple(test.direction, scal) );

	printf("%f %f %f point %f %f %f ray",
			final.all[0].x, final.all[0].y, final.all[0].z,final.all[1].x, final.all[1].y, final.all[1].z);

//	canva_inicializ(&rt_struct, WALL_X, WALL_Y,c_new(0, 0, 0));	
	return (status);

}
