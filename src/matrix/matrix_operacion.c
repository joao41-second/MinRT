/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operacion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:27:20 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 16:49:17 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

int	mat_iqual(t_matrix mat1, t_matrix mat2)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mat1.size)
	{
		x = -1;
		while (++x < mat1.size)
		{
			if (!is_equal_double(mat1.matr[y][x], mat2.matr[y][x]))
				return (FALSE);
		}
	}
	return (TRUE);
}
