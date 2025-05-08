/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_mat_calule.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:36:12 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/08 11:37:07 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void obj_matrix_calcuate(t_mat_calculate *mat)
{
	int x;
	t_matrix temp;

	x = -1;
	temp = mat->restl;

	
	mat_set_multip(&mat->restl_temp, mat->scal, mat->tras);
	if(mat->rot_y.flag != 0)
		mat_set_multip(&mat->restl, mat->restl_temp, mat->rot_y);

	if(mat->rot_x.flag != 0)
		mat_set_multip(&mat->restl_temp, mat->restl, mat->rot_x);
	
	if(mat->rot_z.flag != 0)
		mat_set_multip(&mat->restl, mat->restl_temp, mat->rot_z);	

}
