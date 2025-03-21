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

	ft_start_alloc();
	t_matrix mat1;
	t_matrix mat2;

	t_matrix mult;
	t_matrix invert;

	mat1 = mat_gener(4);
	mat_get_file("matix", mat1);
	
	mat2 = mat_gener(4);
	mat_get_file("matix2", mat2);

	printf("mat1\n");
	mat_print(mat1);
	printf("mat2\n");
	mat_print(mat2);
	printf("mult mat1 * mat2 = \n");
	mult = mat_multip(mat1, mat2);
	mat_print(mult);
	printf("mult invertd = \n");
	invert = mat_inv(mat2);
	mat_print(invert);
	printf("revert mult mult * invert(mat2) = mat1 \n");
	mat_print(mat_multip( mult,invert));

	mat_print(mat_matrix_signal(4));
	

	ft_free_all();
	return (0);
}
