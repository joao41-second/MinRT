/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:50:13 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/06 13:58:49 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minRT.h"
#include "matrix.h"
#include <stdio.h>

void	mat_x_point_aux(t_point *new_, double copy[4][4], int size)
{
	double	nb;
	int		c;
	int		l;

	l = -1;
	while (++l < size)
	{
		c = -1;
		nb = 0;
		while (++c < size)
			nb += copy[l][c];
		new_->val[l] = nb;
	}
}

t_point	mat_x_tuple(t_tuple point, t_matrix mat)
{
	double	va1;
	double	va4;
	double	va3;
	double	va2;
	
	va1 = 0;
	va2 = 0;	
	va3 = 0;
	va4 = 0;
	if (mat.size != 4)
		return (create_tuple(0, 0, 0, 0));
	
	va1 = (point.val[0] * mat.matr[0][0])
		+ (point.val[1] * mat.matr[0][1])
		+ (point.val[2] * mat.matr[0][2])
		+ (point.val[3] * mat.matr[0][3]);
	va2 = (point.val[0] * mat.matr[1][0])
		+ (point.val[1] * mat.matr[1][1])
		+ (point.val[2] * mat.matr[1][2])
		+ (point.val[3] * mat.matr[1][3]);
	va3 = (point.val[0] * mat.matr[2][0])
		+ (point.val[1] * mat.matr[2][1])
		+ (point.val[2] * mat.matr[2][2])
		+ (point.val[3] * mat.matr[2][3]);
	va4 = (point.val[0] * mat.matr[3][0])
		+ (point.val[1] * mat.matr[3][1])
		+ (point.val[2] * mat.matr[3][2])
		+ (point.val[3] * mat.matr[3][3]);
	
	return (create_tuple(va1, va2, va3, va4));
}

void	mat_not_neg_zero(t_matrix *mat)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mat->size)
	{
		x = -1;
		while (++x < mat->size)
			if (mat->matr[y][x] == -0)
				mat->matr[y][x] = 0;
	}
}
