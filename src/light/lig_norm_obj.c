/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lig_norm_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:38:59 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/06 13:58:08 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

t_vector	lig_normalize_sph(t_object sph, t_point p_the_obj)
{
	t_vector	ret;
	t_point		obj_point;
	t_point		obj_word;

	obj_point = mat_x_tuple(p_the_obj, sph.inv_transform);
	obj_word = sub_tuples(obj_point, create_tuple(0, 0, 0, 0));
	ret = mat_x_tuple(obj_word, sph.inv_transpose);
	ret.w = 0;
	return (normalize(ret));
}

t_vector	lig_normalize(t_object obj, t_point p_the_obj)
{
	t_vector	ret;

	if (obj.type == OBJ_SPHERE)
	{
		ret = lig_normalize_sph(obj, p_the_obj);
	}
	return (ret);
}
