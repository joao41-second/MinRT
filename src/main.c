/*                                                        :::      ::::::::   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:19:42 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/19 14:10:28 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix/matrix.h"
#include "minRT.h"
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_minirt	rt_struct;

	(void)ac;
	(void)av;
	ft_start_alloc();
	t_matrix mat1;
	t_matrix mat2;

	mat1 = mat_gener(4);
	mat_get_file("matix", mat1);
	
	mat2 = mat_gener(3);
	mat_get_file("matix2", mat2);
//	mat_print(mat_the_cof(mat1));

	mat_print(mat1);

	printf("\n");
	mat_print(mat_inv(mat1));
//
	double var = mat_det(mat1);
	printf("print the determinat the matrix %f \n",var);

	ft_free_all();
	return (0);
}
