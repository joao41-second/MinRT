/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_type_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:25:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 18:35:39 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"

void	mat_set_vaules_transfrom(t_matrix *mat, t_tuple left,
		t_tuple true_up, t_tuple forward)
{
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

void	mat_set_view_transform(t_matrix *mat_, t_tuple form
		, t_tuple to, t_tuple up)
{
	static t_matrix	mat;
	static t_matrix	trans;
	static int		chek = 0;
	t_tuple			forward;
	t_tuple			left;

	if (chek == 0)
	{
		mat = mat_gener(4);
		trans = mat_gener(4);
		chek = 1;
	}
	mat_set_identity(&mat);
	forward = normalize(sub_tuples(to, form));
	left = cross_product(forward, normalize(up));
	mat_set_vaules_transfrom(&mat, left, cross_product(left, forward), forward);
	mat_set_trans(&trans, -form.x, -form.y, -form.z);
	mat_set_multip(mat_, mat, trans);
}

void	mat_set_rota(t_matrix *mat, char axis, double deg)
{
	mat_set_clear(mat);
	mat_set_scal(mat, 1, 1, 1);
	if (axis == 'y')
	{

		mat_y_rota(mat, deg);
	}
	else if (axis == 'x')

		mat_x_rota(mat, deg);
	else if (axis == 'z')
		mat_z_rota(mat, deg);
	mat->flag = ROTA;
}

void	mat_set_the_cof(t_matrix *mat, t_matrix not_inv)
{
	int			l;
	int			c;

	l = -1;
	while (++l < mat->size)
	{
		c = -1;
		while (++c < mat->size)
		{
			mat->matr[l][c] = mat_set_cof(not_inv, l, c);
		}
	}
}

void	mat_set_inv(t_matrix *mat, t_matrix not_inv)
{
	int			x;
	int			y;

	mat_set_scal(mat, 1, 1, 1);
	mat_set_the_cof(mat, not_inv);
	mat_set_transpose(mat);
	mat_matsh_matrix(mat, '/', mat_set_det(not_inv));
	y = -1;
	while (++y < mat->size)
	{
		x = -1;
		while (++x < mat->size)
			if (mat->matr[y][x] == -0)
				mat->matr[y][x] = 0;
	}
}
