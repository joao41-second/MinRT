/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_type_gener.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:55:59 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 00:49:49 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"

void	mat_set_identity(t_matrix	*matrix_)
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
			if (y_ == x_)
				matrix_->matr[y_][x_] = 1;
		}
	}
	matrix_->flag = IDENTI;
}

void	mat_set_scal(t_matrix *ret, double x, double y, double z)
{
	mat_set_identity(ret);
	ret->matr[0][0] = x;
	ret->matr[1][1] = y;
	ret->matr[2][2] = z;
	ret->flag = SCAL;
}

static void	initialize_matrices(t_matrix *mat, t_matrix *trans, int *check)
{
	if (*check == 0)
	{
		*mat = mat_gener(4);
		*trans = mat_gener(4);
		*check = 1;
	}
}

static void	set_orient(t_matrix *mat, t_tuple form, t_tuple to, t_tuple up)
{
	t_tuple	forward;
	t_tuple	left;
	t_tuple	true_up;

	forward = normalize(sub_tuples(to, form));
	left = cross_product(forward, normalize(up));
	true_up = cross_product(left, forward);
	mat->matr[0][0] = left.x;
	mat->matr[0][1] = left.y;
	mat->matr[0][2] = left.z;
	mat->matr[1][0] = true_up.x;
	mat->matr[1][1] = true_up.y;
	mat->matr[1][2] = true_up.z;
	mat->matr[2][0] = -forward.x;
	mat->matr[2][1] = -forward.y;
	mat->matr[2][2] = -forward.z;
}

void	mat_set_view_transform(t_matrix *mat_, t_tuple form, t_tuple to,
		t_tuple up)
{
	static t_matrix	mat;
	static t_matrix	trans;
	static int		check = 0;

	initialize_matrices(&mat, &trans, &check);
	mat_set_identity(&mat);
	set_orient(&mat, form, to, up);
	mat_set_trans(&trans, -form.x, -form.y, -form.z);
	mat_set_multip(mat_, mat, trans);
}
