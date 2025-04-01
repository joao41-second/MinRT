/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/21 14:45:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"
#include "objects/objects.h"
#include "ray/ray.h"
#include "ray/ray_struct.h"
#include "tuples/tuples.h"
#include <math.h>

int	main(int ac, char **av, char **env)
{
	//t_minirt	rt_struct;
	int			status;

	status = 0;
	(void)ac;
	(void)av;
	(void)env;
	ft_start_alloc();
//	canva_inicializ(&rt_struct, 200, 100, c_new(0, 0, 0));

//	t_matrix mat1;
//	t_shearing val1;
	t_point new ;

	t_sphere new_sph = sphere(create_point(0, 0, 0),1);
	t_intersection interept = ray_int_sphere(ray_gener(create_point(0, 0, -5), create_vector(0, 0, 1)),new_sph);

	printf("the t value is %f and %f \n",interept.t[0],interept.t[1]);
	new = interept.point[0];
	printf("x%f y%f z%f , typ_mat  \n",new.x,new.y,new.z);

	
	ft_free_all();
	return (status);

}
