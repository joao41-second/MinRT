/* ************************************************************************** */
/*                                                                            */
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

int	main(int ac, char **av, char **env)
{
	//t_minirt	rt_struct;
	int			status;

	status = 1;
	(void)ac;
	(void)av;
	(void)env;
	ft_start_alloc();
//	canva_inicializ(&rt_struct, 200, 100, c_new(0, 0, 0));

	t_matrix mat1;

	mat1 = mat_gener_trans(2, 1, 5);
	mat_print(mat1);
	ft_free_all();
	return (status);
}
