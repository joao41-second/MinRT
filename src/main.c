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
#include "../libft/ft_list/list.h"
#include "objects/objects.h"
#include "ray/ray.h"
#include "ray/ray_struct.h"
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	//t_minirt	rt_struct;
	int			status;
	t_list_ *word_objects;

	word_objects = NULL;
	status = 0;
	(void)ac;
	(void)av;
	(void)env;
	ft_start_alloc();
//	canva_inicializ(&rt_struct, 200, 100, c_new(0, 0, 0));

//	t_matrix mat1;
//	t_shearing val1;
	t_point new ;
	t_sphere sph;
	t_sphere sph2;
	t_obj_int intr_in_objc;
	sph = sphere(create_point(0, 0, 0),1) ;
	ft_add_node(&sph,&word_objects );
	sph2 = sphere(create_point(0, 0, 10),1) ;
	ft_add_node(&sph2,&word_objects);
		
	t_obj_int ok;
	ok = ray_for_objects(word_objects,ray_gener(create_point(0,0,-5), create_vector(0,0,1)));

	printf("max %f and min %f\n",ok.max,ok.min);
	
	
	ft_free_all();
	return (status);

}
