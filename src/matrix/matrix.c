/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:33:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 16:46:22 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "../minRT.h"

t_matrix	mat_gener(int x)
{
	t_matrix	matrix_;
	double		**matrix;
	int			x_;
	int			y_;

	matrix_.size = x;
	y_ = -1;
	matrix = ft_malloc(x * sizeof(double *), NULL);
	while (++y_ < x)
	{
		x_ = -1;
		matrix[y_] = ft_malloc(x * sizeof(double), NULL);
		while (++x_ < x)
		{
			matrix[y_][x_] = 0;
		}
	}
	matrix_.matr = matrix;
	matrix_.flag = 0;
	return (matrix_);
}

t_matrix	mat_gener_identity(int x)
{
	t_matrix	matrix_;
	double		**matrix;
	int			x_;
	int			y_;

	matrix_.size = x;
	y_ = -1;
	matrix = ft_malloc(x * sizeof(double *), NULL);
	while (++y_ < x)
	{
		x_ = -1;
		matrix[y_] = ft_malloc(x * sizeof(double), NULL);
		while (++x_ < x)
		{
			matrix[y_][x_] = 0;
			if (y_ == x_)
				matrix[y_][x_] = 1;
		}
	}
	matrix_.matr = matrix;
	matrix_.flag = IDENTI;
	return (matrix_);
}

t_matrix	mat_gener_trans(double x, double y, double z)
{
	t_matrix	ret;

	ret = mat_gener_identity(4);
	if (x == -0)
		x = 0;
	if (y == -0)
		y = 0;
	if (z == -0)
		z = 0;
	ret.matr[0][3] = x;
	ret.matr[1][3] = y;
	ret.matr[2][3] = z;
	ret.flag = TRANS;
	return (ret);
}

t_matrix	mat_gener_scal(double x, double y, double z)
{
	t_matrix	ret;

	ret = mat_gener_identity(4);
	ret.matr[0][0] = x;
	ret.matr[1][1] = y;
	ret.matr[2][2] = z;
	ret.flag = SCAL;
	return (ret);
}

t_matrix	mat_multip(t_matrix mat1, t_matrix mat2)
{
	return (mat_exet(mat1, mat2, mat_mult_matrix));
}
