/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lig_view_transform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:21:49 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 14:22:43 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minRT.h"

t_matrix	lig_view_transform(t_tuple form, t_tuple to, t_tuple up)
{
	t_matrix	mat;
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;

	mat = mat_gener_identity(4);
	forward = normalize(sub_tuples(to, form));
	left = cross_product(forward, normalize(up));
	true_up = cross_product(left, forward);
	mat.matr[0][0] = left.x;
	mat.matr[0][1] = left.y;
	mat.matr[0][2] = left.z;
	mat.matr[1][0] = true_up.x;
	mat.matr[1][1] = true_up.y;
	mat.matr[1][2] = true_up.z;
	mat.matr[2][0] = -forward.x;
	mat.matr[2][1] = -forward.y;
	mat.matr[2][2] = -forward.z;
	mat = mat_multip(mat_cp(mat), mat_gener_trans(-form.x, -form.y, -form.z));
	return (mat);
}
