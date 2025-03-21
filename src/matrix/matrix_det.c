/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_det.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:02:35 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/21 12:44:06 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "matrix.h"
double mat_det2x2(t_matrix mat)
{
	if(mat.size != 2)
		return(0);
	return (mat.matr[0][0]*mat.matr[1][1] -( mat.matr[0][1]*mat.matr[1][0]));
}

t_matrix mat_sub(t_matrix mat,int line,int column)
{
	t_matrix new;
	int l;
	int c;
	int l_sub;
	int c_sub;

	c = -1;
	c_sub = 0;
	if(mat.size <= 2)
		return (mat_gener(2));	
	new = mat_gener(mat.size -1);
	while (++c < mat.size) 
	{
		l = -1;
		l_sub = -1;
		while (++l < mat.size) 
		{ 
			if(l != line && l_sub < new.size && c_sub < new.size)
				new.matr[++l_sub][c_sub] = mat.matr[l][c];
		} 
		if(c != column)
			c_sub++;
	}
	return (new);
}

double mat_det(t_matrix mat)
{
	double ret;
	int i;
	t_matrix sub;
	int mul;

	i = -1;
	if(mat.size == 2)
		return (mat_det2x2(mat));
	ret = 0;
	while (++i < mat.size)
	{
		sub = mat_sub(mat,0,i);
		mul=-1;
		if(0 % 2 == 0 && i % 2 == 0)
			mul = +1;

		ret	+=  mat.matr[0][i] * ( mul * mat_det(sub));
		ft_free(sub.matr);
	}
	return(ret);
}

t_matrix mat_matrix_signal(int size)
{
	int c;
	int l;
	int c_sig;
	int l_sig;
	t_matrix mat;
	
	mat = mat_gener(size);
	l = -1;
	while (++l < mat.size)
	{
		c = -1;
		while (++c < mat.size)
		{
			if(l % 2 == 0)
				mat.matr[c][l] = 1;
			else 
				mat.matr[c][l] = -1;
			if(c % 2 != 0)
				mat.matr[c][l] = -mat.matr[c][l];
				

		}	
	}
	return (mat);
}


double mat_cof(t_matrix mat,int line,int column)
{
	double ret;
	t_matrix sub;
	t_matrix sub_signal;
	int mul;

	sub_signal = mat_matrix_signal(mat.size -1);
	sub = mat_sub(mat,line,column);	
	sub_signal = mat_matrix_signal(mat.size);
	mul = sub_signal.matr[column][line];
	ret	= ( mul * mat_det(sub));
	ft_free(sub.matr);
	return(ret);
}


