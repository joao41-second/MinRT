/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:56:27 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 16:48:02 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "matrix.h"

t_matrix	mat_the_cof(t_matrix mat)
{
	t_matrix	new_mat;
	int			l;
	int			c;

	l = -1;
	new_mat = mat_gener(mat.size);
	while (++l < mat.size)
	{
		c = -1;
		while (++c < mat.size)
		{
			new_mat.matr[l][c] = mat_cof(mat, l, c);
		}
	}
	return (new_mat);
}

t_matrix	mat_inv(t_matrix mat)
{
	t_matrix	invertd;
	int			x;
	int			y;

	invertd = mat_the_cof(mat);
	mat_trans(&invertd);

	mat_matsh_matrix(&invertd, '/', mat_det(mat));

	y = -1;
	while (++y < mat.size)
	{
		x = -1;
		while (++x < mat.size)
			if (invertd.matr[y][x] == -0)
				invertd.matr[y][x] = 0;
	}
	return (invertd);
}
