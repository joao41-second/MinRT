/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lig_norm_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:38:59 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/17 17:40:30 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "light.h"

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

t_vector	lig_normalize_plane(t_object pln, t_point point)
{
	t_vector	ret;

	(void)point;
	ret = pln.u_data.plane.normal;
	return (ret);
}

t_vector	lig_normalize_cyl(t_object obj, t_point p_the_obj)
{
	t_cylinder	*cylinder;
	t_vector	obj_point;
	double		dist;
	t_point		projected;
	t_vector	normal;

	cylinder = &obj.u_data.cylinder;
	obj_point = mat_x_tuple(p_the_obj, obj.inv_transform);
	dist = pow(obj_point.x, 2) + pow(obj_point.z, 2);
	if (dist < pow(cylinder->radius, 2))
	{
		if (obj_point.y >= cylinder->maximum - EPSILON)
			return (create_vector(0, 1, 0));
		if (obj_point.y <= cylinder->minimum + EPSILON)
			return (create_vector(0, -1, 0));
	}
	projected = create_point(obj_point.x, 0, obj_point.z);
	normal = sub_tuples(projected, create_point(0, 0, 0));
	return (normalize(normal));
}

t_vector	lig_normalize(t_object obj, t_point p_the_obj)
{
	t_vector	ret;

	ret = create_tuple(0, 0, 0, 0);
	if (obj.type == OBJ_SPHERE)
	{
		ret = lig_normalize_sph(obj, p_the_obj);
	}
	else if (obj.type == OBJ_PLANE)
		ret = obj.u_data.plane.normal;
	else if (obj.type == OBJ_TRIANGLE || obj.type == OBJ_SQUARE)
	{
		ret = obj.u_data.triangle.normal;
	}
	else if (obj.type == OBJ_CYLINDER)
	{
		ret = lig_normalize_cyl(obj, p_the_obj);
	}
	else
	{
		ret = create_vector(0, 0, 0);
	}
	return (ret);
}
