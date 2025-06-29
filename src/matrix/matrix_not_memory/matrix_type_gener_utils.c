/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_type_gener_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:55:59 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 00:46:36 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"

void	mat_set_clear(t_matrix	*matrix_)
{
	int	x_;
	int	y_;
	int	x;

	x = matrix_->size;
	y_ = -1;
	while (++y_ < x)
	{
		x_ = -1;
		while (++x_ < x)
		{
			matrix_->matr[y_][x_] = 0;
		}
	}
	matrix_->flag = 0;
}

void	mat_set_trans(t_matrix *ret, double x, double y, double z)
{
	mat_set_identity(ret);
	if (x == -0)
		x = 0;
	if (y == -0)
		y = 0;
	if (z == -0)
		z = 0;
	ret->matr[0][3] = x;
	ret->matr[1][3] = y;
	ret->matr[2][3] = z;
	ret->flag = TRANS;
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
