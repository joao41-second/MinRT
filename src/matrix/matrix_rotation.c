/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:53:47 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/04 12:39:23 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include <math.h>
#define M_PI 3.14159265358979323846

double deg_to_radians(double deg)
{
	double ret;
	ret = deg * M_PI/180;	
	return (ret);
}

void mat_x_rota(t_matrix *mat,double rad)
{
	mat->matr[1][1] = cos(rad);
	mat->matr[1][2] = -sin(rad);
	mat->matr[2][1] = sin(rad);
	mat->matr[2][2] = cos(rad);
}

void mat_y_rota(t_matrix *mat,double rad)
{
	mat->matr[0][0] = cos(rad);
	mat->matr[2][0] = -sin(rad);
	mat->matr[0][2] = sin(rad);
	mat->matr[2][2] = cos(rad);
}

void mat_z_rota(t_matrix *mat,double rad)
{
	mat->matr[0][0] = cos(rad);
	mat->matr[0][1] = -sin(rad);
	mat->matr[1][0] = sin(rad);
	mat->matr[1][1] = cos(rad);
}

t_rotation mat_gener_rota(char axis,double deg)
{
	t_rotation ret;

	ret = mat_gener_identity(4);
	if(axis == 'x')	
	{
		mat_x_rota(&ret, deg_to_radians(deg));
	}
	else if(axis == 'y')	
		mat_y_rota(&ret, deg_to_radians(deg));
	else if(axis == 'z')	
		mat_z_rota(&ret, deg_to_radians(deg));
	else
		return(ret);	
	ret.flag = ROTA;
	return(ret);
}
