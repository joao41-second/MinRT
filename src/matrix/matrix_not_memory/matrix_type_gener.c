/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_type_gener.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:55:59 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/08 11:02:42 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minRT.h"

void mat_set_clear(t_matrix	*matrix_)
{
	int			x_;
	int			y_;
	int 			x;

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
void mat_set_identity(t_matrix	*matrix_)
{
	int			x_;
	int			y_;
	int 			x;

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

void	mat_set_trans(t_matrix *ret,double x, double y, double z)
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

void	mat_set_scal(t_matrix *ret,double x, double y, double z)
{

	mat_set_identity(ret);
	ret->matr[0][0] = x;
	ret->matr[1][1] = y;
	ret->matr[2][2] = z;
	ret->flag = SCAL;
}

void	mat_set_multip(t_matrix *resolt,t_matrix mat1, t_matrix mat2)
{
	int x;
	int y;
	y= -1;
	mat_set_clear(resolt);
	while (++y < mat1.size) 
	{
		x = -1;
		while (++x < mat1.size) 
		{
			resolt->matr[y][x] = (mat1.matr[y][0]*mat2.matr[0][x]) +  
				(mat1.matr[y][1]*mat2.matr[1][x]) + 
				(mat1.matr[y][2]*mat2.matr[2][x])+
				(mat1.matr[y][3]*mat2.matr[3][x]);
		}
	}
}

void	mat_set_view_transform(t_matrix *mat_,t_tuple form, t_tuple to, t_tuple up)
{
	static t_matrix	mat;
	static t_matrix	trans;
	static int chek = 0;
	
	if(chek == 0)
	{
		mat = mat_gener(4);
		trans = mat_gener(4);
		chek = 1;
	}

	mat_set_identity(&mat);
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;

	forward = normalize(sub_tuples(to, form));
	left = cross_product(forward, normalize(up));
	true_up = cross_product(left, forward);
	mat.matr[0][0] = left.x;
	mat.matr[0][1] = left.y;
	mat.matr[0][2] = left.z;
	mat.matr[1][0] = true_up.x;
	mat.matr[1][1] = true_up.y;
	mat.matr[1][2] = true_up.z;
	mat.matr[2][0] = -forward.x;
	mat.matr[2][1] = -forward.y;
	mat.matr[2][2] = -forward.z;
	
	mat_set_trans(&trans, -form.x, -form.y, -form.z);
	mat_set_multip(mat_, mat, trans);
}

void	mat_set_rota(t_matrix mat,char axis, double deg)
{
	t_rotation	ret;

	ret = mat_gener_identity(4);
	if (axis == 'x')
	{
		mat_x_rota(&mat,deg);
	}
	else if (axis == 'y')
		mat_y_rota(&mat, deg);
	else if (axis == 'z')
		mat_z_rota(&mat, deg);
	ret.flag = ROTA;
}

