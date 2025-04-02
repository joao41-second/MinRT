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
	sph2 = sphere(create_point(0, 0, 10),1) ;
	ft_add_node(&sph2,&word_objects);
		
	canva_inicializ(&rt_struct, 500, 500,c_new(0, 0, 0));	
	return (status);

}
