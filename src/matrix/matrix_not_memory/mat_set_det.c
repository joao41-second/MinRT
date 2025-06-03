
#include "../../minRT.h"
#include "../matrix.h"


t_matrix	mat_set_3_sub(t_matrix mat, int line, int column)
{
	static	t_matrix	new;
	static int ok = 0;
	int			l;
	int			c;
	int			l_sub;
	int			c_sub;

	c = -1;
	c_sub = 0;
	if(ok != 10)
	{
		new = mat_gener(3);
		ok = 10;
	}
	mat_set_clear(&new);
	while (++c < mat.size)
	{
		l = -1;
		l_sub = -1;
		while (++l < mat.size)
		{
			if (l != line && l_sub < new.size && c_sub < new.size)
				new.matr[++l_sub][c_sub] = mat.matr[l][c];
		}
		if (c != column)
			c_sub++;
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
		sub = mat_set_3_sub(mat, 0, i);
		mul = -1;
		if (0 % 2 == 0 && i % 2 == 0)
			mul = +1;
		ret += mat.matr[0][i] * (mul * mat_det2x2(sub));
	}
	return (ret);
}



double	mat_set_cof(t_matrix mat, int line, int column)
{
	double		ret;
	t_matrix	sub;
	static t_matrix	sub_signal;
	int			mul;

	sub = mat_set_3_sub(mat, line, column);
	if(sub_signal.flag != 23)
	{
	sub_signal = mat_matrix_signal(mat.size);
	sub_signal.flag = 23;
	}
	mul = sub_signal.matr[column][line];
	ret = (mul * mat_det(sub));
	return (ret);
}
