/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lig_norm_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:38:59 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/19 15:44:34 by rerodrig         ###   ########.fr       */
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

t_vector	lig_normalize_tri(t_object obj, t_point p_the_obj)
{
    t_triangle triangle;
    t_vector edge1;
    t_vector edge2;
    t_vector normal;
	
    triangle = obj.u_data.triangle;
    edge1 = sub_tuples(triangle.p2, triangle.p1);
    edge2 = sub_tuples(triangle.p3, triangle.p1);
    normal = cross_product(edge1, edge2);
    return normalize(normal);
}

t_vector	lig_normalize_cyl(t_object obj, t_point p_the_obj)
{
    t_cylinder *cylinder;
    t_vector obj_point;
    double dist;
	
    cylinder = &obj.u_data.cylinder;
    obj_point = mat_x_tuple(p_the_obj, obj.inv_transform);
    dist = pow(obj_point.x, 2) + pow(obj_point.z, 2);
    if (dist < pow(cylinder->radius, 2)) {
        if (obj_point.y >= cylinder->maximum - EPSILON) {
            return create_vector(0, 1, 0);
        }
        if (obj_point.y <= cylinder->minimum + EPSILON) {
            return create_vector(0, -1, 0);
        }
    }
    t_point projected = create_point(obj_point.x, 0, obj_point.z);
    t_vector normal = sub_tuples(projected, create_point(0, 0, 0));
    return normalize(normal);
}


t_vector	lig_normalize(t_object obj, t_point p_the_obj)
{
	t_vector	ret;

	if (obj.type == OBJ_SPHERE)
		ret = lig_normalize_sph(obj, p_the_obj);
	else if (obj.type == OBJ_PLANE)
		ret = lig_normalize_plane(obj, p_the_obj);
	else if (obj.type == OBJ_TRIANGLE) 
		ret = lig_normalize_tri(obj, p_the_obj);
	else if (obj.type == OBJ_CYLINDER)
		ret = lig_normalize_cyl(obj, p_the_obj);
	else
	{
		ret = create_vector(0, 0, 0);
	}
	return (ret);
}
