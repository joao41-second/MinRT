/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:53:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/19 10:11:44 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

double	deg_to_radians(double deg)
{
	double	ret;

	ret = deg * M_PI / 180;
	return (ret);
}

void	mat_x_rota(t_matrix *mat, double rad)
{
	mat->matr[1][1] = cos(rad);
	mat->matr[1][2] = -sin(rad);
	mat->matr[2][1] = sin(rad);
	mat->matr[2][2] = cos(rad);
}

void	mat_y_rota(t_matrix *mat, double rad)
{
	mat->matr[0][0] = cos(rad);
	mat->matr[2][0] = -sin(rad);
	mat->matr[0][2] = sin(rad);
	mat->matr[2][2] = cos(rad);
}

void	mat_z_rota(t_matrix *mat, double rad)
{
	mat->matr[0][0] = cos(rad);
	mat->matr[0][1] = -sin(rad);
	mat->matr[1][0] = sin(rad);
	mat->matr[1][1] = cos(rad);
}

t_rotation	mat_gener_rota(char axis, double deg)
{
	t_rotation	ret;

	ret = mat_gener_identity(4);
	if (axis == 'x')
	{
		mat_x_rota(&ret, deg_to_radians(deg));
	}
	else if (axis == 'y')
		mat_y_rota(&ret, deg_to_radians(deg));
	else if (axis == 'z')
		mat_z_rota(&ret, deg_to_radians(deg));
	else
		return (ret);
	ret.flag = ROTA;
	return (ret);
}
t_matrix mat_rotate(t_vector axis, double angle)
{
    double cos_a;
    double sin_a;
    double one_minus_cos;
    t_matrix rotation;
    
	cos_a = cos(angle);
    sin_a = sin(angle);
    one_minus_cos = 1.0 - cos_a;
    rotation = mat_gener_identity(4);
    axis = normalize(axis);
    rotation.matr[0][0] = cos_a + axis.x * axis.x * one_minus_cos;
    rotation.matr[0][1] = axis.x * axis.y * one_minus_cos - axis.z * sin_a;
    rotation.matr[0][2] = axis.x * axis.z * one_minus_cos + axis.y * sin_a;
    rotation.matr[1][0] = axis.y * axis.x * one_minus_cos + axis.z * sin_a;
    rotation.matr[1][1] = cos_a + axis.y * axis.y * one_minus_cos;
    rotation.matr[1][2] = axis.y * axis.z * one_minus_cos - axis.x * sin_a;
    rotation.matr[2][0] = axis.z * axis.x * one_minus_cos - axis.y * sin_a;
    rotation.matr[2][1] = axis.z * axis.y * one_minus_cos + axis.x * sin_a;
    rotation.matr[2][2] = cos_a + axis.z * axis.z * one_minus_cos;
    return rotation;
}
