/* ************************************************************************** */
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

void mat_x_point_aux(t_point *new_,double copy[4][4],int size)
{
	double nb;
	int c;
	int l;

	l = -1;
	while (++l < size)
	{
		c = -1;
		nb = 0;
		while (++c < size)
			nb += copy[l][c];
		new_->val[l] = nb;
	}
}

t_point mat_x_tuple(t_tuple point,t_matrix mat)
{

	double va1;
	double va4;
	double va3;
	double va2;
	if(mat.size != 4)
		return (create_point(0, 0, 0));

	va1 = (point.val[0]*mat.matr[0][0]) + (point.val[1]*mat.matr[0][1]) + (point.val[2]*mat.matr[0][2]);

	va2 = (point.val[0]*mat.matr[1][0]) + (point.val[1]*mat.matr[1][1]) + (point.val[2]*mat.matr[1][2]);

	va3 = (point.val[0]*mat.matr[2][0]) + (point.val[1]*mat.matr[2][1]) + (point.val[2]*mat.matr[2][2]);

	va4 = (point.val[0]*mat.matr[3][0]) + (point.val[1]*mat.matr[3][1]) + (point.val[2]*mat.matr[3][2]);

	if(va4 == 0)
		va4 = 1;

	return(create_point(va1/va4, va2/va4, va3/va4));
}



