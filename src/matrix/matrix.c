/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:47:38 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/18 20:00:30 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "../minRT.h"
#include <unistd.h>

t_matrix mat_gener(int x,int y)
{
	t_matrix matrix_;
	double **matrix;
	int x_;
	int y_;
	
	matrix_.x = x;
	matrix_.y = y;
	y_ = -1;
	matrix = ft_malloc(y * sizeof(double *), NULL);
	while (++y_ <= y)
	{
		x_ = -1;
		matrix[y_] = ft_malloc(x * sizeof(double),NULL);
		while(++x_ <= x)
		{
			matrix[y_][x_] = 0;	
		}
	}
	matrix_.matr = matrix;	
	return (matrix_);
}


double mat_mult_matrix(int *y,int*x,t_matrix *mat1,t_matrix *mat2)
{
	double ret;
	double *m1;
	double *m2;
	int i; 

	ft_pocket_new("mult");
	i = -1;
	m1 = ft_malloc(mat1->x*sizeof(double), NULL);
	m2 = ft_malloc(mat1->y*sizeof(double), NULL);
	while (++i <= *x)
		m1[i] = mat1->matr[*y][i];
	i = -1;
	while (++i <= *y)
		m2[i] = mat1->matr[i][*x];
	i = -1;
	while (++i <= *y)
		ret +=  m1[i] * m2[i]; 
	ft_free_all_pocket("mult");
	return (ret);
}


t_matrix mat_exet(t_matrix mat1, t_matrix mat2,double f(const void*, const void*,const void*,const void*))
{
	t_matrix new_matrix;
	
	if(mat1.x != mat2.x || mat1.y != mat2.y)
	{
		ft_printf_fd(2, "the matrix not euqual");
		return (mat_gener(2,2));
	}
	new_matrix = mat_gener(mat1.x, mat1.y);
	int x;
	int y;
	
	y = -1;
	while (++y <= mat1.y)
	{
		x = -1;
		while(++x <= mat1.x)
		{
			new_matrix.matr[y][x] = f(&y,&x,&mat1,&mat2);
		}
	}
	return(new_matrix);

}

t_matrix mat_multip(t_matrix mat1,t_matrix mat2)
{
	return 	mat_exet(mat1, mat2,mat_mult_matrix);
}

void mat_print(const t_matrix matrix)
{
	int x;
	int y;
	
	y = -1;
	while (++y <= matrix.y)
	{
		x = -1;
		while(++x <= matrix.x)
		{
			printf("| %f |", matrix.matr[y][x]);
		}
		printf("\n");
	}	
}
