/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:01:18 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/04 19:37:16 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

double	mat_mult_matrix(int *y, int *x, t_matrix *mat1, t_matrix *mat2)
{
	double		ret;
	double		*m1;
	double		*m2;
	int			i;

	ft_pocket_new("mult");
	ret = 0;
	i = -1;
	m1 = ft_malloc(mat1->size * sizeof(double), NULL);
	m2 = ft_malloc(mat1->size * sizeof(double), NULL);
	while (++i < mat1->size)
		m1[i] = mat2->matr[*y][i];
	i = -1;
	while (++i < mat1->size)
		m2[i] = mat1->matr[i][*x];
	i = -1;
	while (++i < mat1->size)
	{
		ret = ret + (m1[i] * m2[i]);
	}
	ft_free_all_pocket("mult");
	return (ret);
}

double	mat_copy(int *y, int*x, t_matrix *mat1, t_matrix *mat2)
{
	(void)mat2;
	return (mat1->matr[*y][*x]);
}

double	mat_transposing(int *y, int*x, t_matrix *mat1, t_matrix *mat2)
{
	(void)mat1;
	return (mat2->matr[*x][*y]);
}

t_matrix	mat_exet(t_matrix mat1, t_matrix mat2, double f( int*,
			int*, t_matrix*, t_matrix*))
{
	t_matrix	new_matrix;
	int			x;
	int			y;

	if (mat1.size != mat2.size)
	{
		ft_printf_fd(2, "the matrix not euqual");
		return (mat_gener(2));
	}
	new_matrix = mat_gener(mat1.size);
	y = -1;
	while (++y < mat1.size)
	{
		x = -1;
		while (++x < mat1.size)
		{
			new_matrix.matr[y][x] = f(&y, &x, &mat1, &mat2);
		}
	}
	return (new_matrix);
}

void	mat_print(const t_matrix matrix)
{
	int		x;
	int		y;

	y = -1;
	while (++y < matrix.size)
	{
		x = -1;
		while (++x < matrix.size)
		{
			printf("|  %10.5f ", matrix.matr[y][x]);
		}
		printf("\n");
	}
}
