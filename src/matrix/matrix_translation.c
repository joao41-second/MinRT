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

t_point mat_x_point(t_point point,t_matrix mat)
{
	int c;
	int l;
	double nb;
	t_matrix copy;
	t_point new_;

	copy = mat_cp(mat);
	if(copy.size != 4)
		return (create_point(point.val[0],point.val[1], point.val[2]));
	new_ = create_point(0, 0, 0);
	l = -1;
	while (++l < copy.size)
	{
		c = -1;
		while (++c < copy.size)
			copy.matr[l][c] = copy.matr[l][c]  + point.val[c]/10;
	}	
	l = -1;
	while (++l < copy.size)
	{
		c = -1;
		nb = 0;
		while (++c < copy.size)
			nb += copy.matr[l][c];
		new_.val[l] = nb;
	}
	return(new_);
}
