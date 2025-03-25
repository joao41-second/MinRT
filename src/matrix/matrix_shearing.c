/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_shearing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:28:53 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/25 12:41:36 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "matrix.h"


t_mat_hearing 	mat_gener_hearing(t_hearing values)
{	
	t_rotation ret;

	ret = mat_gener_identity(4);
	ret.matr[0][1] = values.x_y;
	ret.matr[0][2] = values.x_z;

	ret.matr[1][0] = values.y_x;
	ret.matr[1][2] = values.y_z;

	ret.matr[0][2] = values.z_x;
	ret.matr[1][2] = values.z_y;

	ret.flag = HEARING;
	return(ret);

}

