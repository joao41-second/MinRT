/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_updated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:44:53 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 01:40:18 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "matrix.h"

void	mat_mult_ntm(const t_matrix mat1, const t_matrix mat2, t_matrix *new)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mat1.size)
	{
		x = -1;
		while (++x < mat1.size)
		{
			new->matr[y][x] = (mat1.matr[y][0] * mat2.matr[0][x])
				+ (mat1.matr[y][1] * mat2.matr[1][x])
				+ (mat1.matr[y][2] * mat2.matr[2][x])
				+ (mat1.matr[y][3] * mat2.matr[3][x]);
		}
	}
}

void	mat_view_transform_ntm(t_matrix *mat, t_tuple form, t_tuple to,
		t_tuple up)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;

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
	mat_mult_ntm(*mat, mat_gener_trans(-form.x, -form.y, -form.z), mat);
}

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
