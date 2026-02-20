/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_type_utilits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:34:29 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 18:35:40 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"

void	mat_set_transpose(t_matrix *mat)
{
	static int			ok = 0;
	static t_matrix		new_matrix;
	int					y;
	int					x;

	if (ok != 1)
	{
		new_matrix = mat_gener(4);
		ok = 1;
	}
	mat_set_cp(&new_matrix, mat);
	y = -1;
	while (++y < mat->size)
	{
		x = -1;
		while (++x < mat->size)
		{
			mat->matr[y][x] = mat_transposing(&y, &x, &new_matrix, &new_matrix);
		}
	}
}

void	mat_set_multip(t_matrix *resolt, t_matrix mat1, t_matrix mat2)
{
	int	x;
	int	y;

	y = -1;
	mat_set_clear(resolt);
	while (++y < mat1.size)
	{
		x = -1;
		while (++x < mat1.size)
		{
			resolt->matr[y][x] = (mat1.matr[y][0] * mat2.matr[0][x])
				+ (mat1.matr[y][1] * mat2.matr[1][x])
				+ (mat1.matr[y][2] * mat2.matr[2][x])
				+ (mat1.matr[y][3] * mat2.matr[3][x]);
		}
	}
}
