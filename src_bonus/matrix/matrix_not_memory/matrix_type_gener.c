/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_type_gener.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:55:59 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 18:35:34 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"

void	mat_set_clear(t_matrix	*matrix_)
{
	int			x_;
	int			y_;
	int			x;

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

void	mat_set_cp(t_matrix	*matrix_, t_matrix *copied)
{
	int			x_;
	int			y_;
	int			x;

	x = matrix_->size;
	y_ = -1;
	while (++y_ < x)
	{
		x_ = -1;
		while (++x_ < x)
		{
			matrix_->matr[y_][x_] = copied->matr[y_][x_];
		}
	}
	matrix_->flag = copied->flag;
}

void	mat_set_identity(t_matrix	*matrix_)
{
	int			x_;
	int			y_;
	int			x;

	x = matrix_->size;
	y_ = -1;
	while (++y_ < x)
	{
		x_ = -1;
		while (++x_ < x)
		{
			matrix_->matr[y_][x_] = 0;
			if (y_ == x_)
				matrix_->matr[y_][x_] = 1;
		}
	}
	matrix_->flag = IDENTI;
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

void	mat_set_scal(t_matrix *ret, double x, double y, double z)
{
	mat_set_identity(ret);
	ret->matr[0][0] = x;
	ret->matr[1][1] = y;
	ret->matr[2][2] = z;
	ret->flag = SCAL;
}
