/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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
	start_word(&rt_struct);
	t_ray ray;
	t_color color;
	start_word(&rt_struct);

	 ray = ray_gener(create_point(0, 0, -5), create_vector(0, 0, 1));
	 color = lig_color_at(&rt_struct, ray);
	 printf("color %f %f %f \n",color.red,color.blue,color.green);



	//canva_inicializ(&rt_struct, WALL_X, WALL_Y,c_new(0, 0, 0));	
	return (status);

}
