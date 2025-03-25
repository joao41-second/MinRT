/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:53:45 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/24 11:53:58 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "matrix.h"

void mat_x_point_aux(t_point *new_,t_matrix copy)
{
	double nb;
	int c;
	int l;

	l = -1;
	while (++l < copy.size)
	{
		c = -1;
		nb = 0;
		while (++c < copy.size)
			nb += copy.matr[l][c];
		new_->val[l] = nb;
	}
}

t_point mat_x_tuple(t_tuple point,t_matrix mat)
{
	int c;
	int l;
	t_matrix copy;
	t_point new_;

	if(mat.size != 4 || (mat.flag == TRANS && point.w != 1))
		return (create_point(point.val[0],point.val[1], point.val[2]));	
	copy = mat_cp(mat);
	new_ = create_point(0, 0, 0);
	l = -1;
	while (++l < copy.size)
	{
		c = -1;
		while (++c < copy.size)
			copy.matr[l][c] = copy.matr[l][c]  * point.val[c];
	}	
	mat_x_point_aux(&new_, copy);
	mat_free(&copy);
	return(new_);
}
