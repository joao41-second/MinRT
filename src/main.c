/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/21 14:45:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix/matrix.h"
#include "minRT.h"
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

	t_matrix mat1;
	//t_matrix inv;
	mat1 = mat_gener_rota('x', 45);
	mat_print(mat1);
//	inv = mat_inv(mat1);
	t_point new =	mat_x_tuple(create_point(0,1,  0), mat1);

	printf("x%f y%f z%f , typ_mat  %d\n",new.x,new.y,new.z,mat1.flag);

	
	ft_free_all();
	return (status);

}
