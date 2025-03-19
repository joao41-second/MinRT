/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:19:42 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/19 11:25:35 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix/matrix.h"
#include "minRT.h"

int	main(int ac, char **av, char **env)
{
	t_minirt	rt_struct;

	(void)ac;
	(void)av;
	ft_start_alloc();
	t_matrix matrix;
	t_matrix mat2;

	matrix = mat_gener(4);

	mat_get_file("matix", matrix);
	
	mat2 = mat_gener(4);

	mat_get_file("matix2", mat2);
	printf("mat 1\n");
	mat_print(matrix);

	printf("mat 2\n");
	mat_print(mat2);
	
	printf("mat x\n");
	mat_print(mat_multip(mat2, matrix));
//	canva_inicializ(&rt_struct, 200, 100, c_new(0, 0, 0));
	ft_free_all();
	return (0);
}
