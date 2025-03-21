/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:47:38 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/21 13:22:38 by jperpct          ###   ########.fr       */
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
	return (matrix_);
}

t_matrix	mat_multip(t_matrix mat1, t_matrix mat2)
{
	return (mat_exet(mat1, mat2, mat_mult_matrix));
}

void	mat_print(const t_matrix matrix)
{
	int		x;
	int		y;

	y = -1;
	while (++y < matrix.size)
	{
		x = -1;
		while (++x < matrix.size)
		{
			printf("|  %10.5f ", matrix.matr[y][x]);
		}
		printf("\n");
	}
}
