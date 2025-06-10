/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_set_det.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:00:10 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 18:24:18 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../minRT.h"
#include "../matrix.h"

t_matrix	mat_set_3_sub(t_matrix mat, int line, int column)
{
	static t_matrix	new;
	static int		ok = 0;
	int				i[4];

	i[0] = -1;
	i[3] = 0;
	if (ok != 10)
	{
		new = mat_gener(3);
		ok = 10;
	}
	mat_set_clear(&new);
	new.size = mat.size -1;
	while (++i[0] < mat.size)
	{
		i[1] = -1;
		i[2] = -1;
		while (++i[1] < mat.size)
			if (i[1] != line && i[2] < new.size && i[3] < new.size)
				new.matr[++i[2]][i[3]] = mat.matr[i[1]][i[0]];
		if (i[0] != column)
			i[3]++;
	}
	return (new);
}

t_matrix	mat_set_2_sub(t_matrix mat, int line, int column)
{
	static t_matrix	new;
	static int		ok = 0;
	int				i[4];

	i[1] = -1;
	i[3] = 0;
	if (ok != 10)
	{
		new = mat_gener(2);
		ok = 10;
	}
	mat_set_clear(&new);
	while (++i[1] < mat.size)
	{
		i[0] = -1;
		i[2] = -1;
		while (++i[0] < mat.size)
		{
			if (i[0] != line && i[2] < new.size && i[3] < new.size)
				new.matr[++i[2]][i[3]] = mat.matr[i[0]][i[1]];
		}
		if (i[1] != column)
			i[3]++;
	}
	return (new);
}

double	mat_set_det(t_matrix mat)
{
	double		ret;
	int			i;
	t_matrix	sub;
	int			mul;

	i = -1;
	if (mat.size == 2)
		return (mat_det2x2(mat));
	ret = 0;
	while (++i < mat.size)
	{
		if (mat.size == 3)
			sub = mat_set_2_sub(mat, 0, i);
		else
			sub = mat_set_3_sub(mat, 0, i);
		mul = -1;
		if (0 % 2 == 0 && i % 2 == 0)
			mul = +1;
		ret += mat.matr[0][i] * (mul * mat_set_det(sub));
	}
	return (ret);
}

double	mat_set_cof(t_matrix mat, int line, int column)
{
	double				ret;
	t_matrix			sub;
	static t_matrix		sub_signal;
	int					mul;

	sub = mat_set_3_sub(mat, line, column);
	if (sub_signal.flag != 23)
	{
		sub_signal = mat_matrix_signal(mat.size);
		sub_signal.flag = 23;
	}
	mul = sub_signal.matr[column][line];
	ret = (mul * mat_set_det(sub));
	return (ret);
}
