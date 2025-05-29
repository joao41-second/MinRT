/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lig_norm_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:38:59 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/07 11:41:04 by rerodrig         ###   ########.fr       */
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

	t_plane *plan;

	ret = pln.u_data.plane.normal;
	//ret.w = 0;
	return(ret);
}
t_vector	lig_normalize(t_object obj, t_point p_the_obj)
{
	t_vector	ret;
	t_plane 	plan;

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
		t_vector obj_point = mat_x_tuple(p_the_obj, obj.inv_transform);
		t_vector obj_word = sub_tuples(obj_point, create_tuple(0, 0, 0, 0));
		ret = mat_x_tuple(obj_word, obj.inv_transpose);
		ret.w = 0;
	}
	else
	{
		ret = create_vector(0, 0, 0);
	}
	return (ret);
}
