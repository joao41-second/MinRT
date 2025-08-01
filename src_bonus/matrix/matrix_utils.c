/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:11:40 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 18:37:53 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "matrix.h"
#include <stdio.h>

void	mat_get_file(char *file, t_matrix mat)
{
	char	*line;
	int		fd;
	char	**nb_char;
	int		i;
	int		y;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	ft_pocket_new("gete_file");
	line = ft_add_memory(get_next_line(fd), NULL);
	y = -1;
	while (line != NULL && ++y < mat.size)
	{
		i = -1;
		nb_char = ft_split(line, '|');
		while (nb_char[++i] != NULL && i < mat.size)
			mat.matr[y][i] = ft_atoi(nb_char[i]);
		line = ft_add_memory(get_next_line(fd), NULL);
	}
	close(fd);
	ft_free_all_pocket("gete_file");
}

t_matrix	mat_cp(t_matrix mat)
{
	t_matrix	ret;

	ret = mat_exet(mat, mat, mat_copy);
	ret.flag = mat.flag;
	return (ret);
}

void	mat_trans(t_matrix *mat)
{
	t_matrix	tmp;
	t_matrix	ret;	

	tmp = mat_cp(*mat);
	ret = mat_exet(*mat, tmp, mat_transposing);
	mat_free(mat);
	*mat = ret;
	mat_free(&tmp);
}

void	mat_free(t_matrix *matrix)
{
	int		y_;

	y_ = -1;
	while (++y_ < matrix->size)
	{
		ft_free(matrix->matr[y_]);
	}
	ft_free(matrix);
	matrix = NULL;
}

void	mat_matsh_matrix(t_matrix *mat, char math, double nb)
{
	int		l;
	int		c;
	double	temp;

	l = -1;
	while (++l < mat->size)
	{
		c = -1;
		while (++c < mat->size)
		{
			temp = mat->matr[l][c];
			mat->matr[l][c] = 0;
			if (math == '+')
				mat->matr[l][c] = temp + nb;
			if (math == '-')
				mat->matr[l][c] = temp - nb;
			if (math == '*')
				mat->matr[l][c] = temp * nb;
			if (math == '/')
			{
				mat->matr[l][c] = temp / nb;
			}
		}
	}
}
