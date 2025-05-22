/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:11:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 01:40:08 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "matrix.h"
#include <stdio.h>

t_matrix	mat_cp(t_matrix mat)
{
	t_matrix	ret;

	ret = mat_exet(mat, mat, mat_copy);
	ret.flag = mat.flag;
	return (ret);
}

void	mat_trans(t_matrix *mat)
{
	t_matrix	tmp;
	t_matrix	ret;

	tmp = mat_cp(*mat);
	ret = mat_exet(*mat, tmp, mat_transposing);
	mat_free(mat);
	*mat = ret;
	mat_free(&tmp);
}

void	mat_free(t_matrix *matrix)
{
	int		y_;

	y_ = -1;
	while (++y_ < matrix->size)
	{
		ft_free(matrix->matr[y_]);
	}
	ft_free(matrix);
	matrix = NULL;
}

static double	apply_math_operation(double temp, char math, double nb)
{
	if (math == '+')
		return (temp + nb);
	if (math == '-')
		return (temp - nb);
	if (math == '*')
		return (temp * nb);
	if (math == '/')
	{
		if (nb != 0)
			return (temp / nb);
	}
	return (temp);
}

void	mat_matsh_matrix(t_matrix *mat, char math, double nb)
{
	int		l;
	int		c;

	l = -1;
	while (++l < mat->size)
	{
		c = -1;
		while (++c < mat->size)
		{
			mat->matr[l][c] = apply_math_operation(mat->matr[l][c], math, nb);
		}
	}
}
