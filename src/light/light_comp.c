/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:08:21 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/22 09:50:14 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "light.h"
#include <stdio.h>

void	lig_print_tuple(t_tuple tuple)
{
	if (tuple.w == 1)
	{
		printf("point %f %f %f \n", tuple.x, tuple.y, tuple.z);
	}
	else
		printf("vect %10.5f %f %f \n", tuple.x, tuple.y, tuple.z);
}

t_computations	lig_prepare_computations(t_obj_int inter, t_ray ray)
{
	t_computations	ret;
	t_sphere	*sph;

	sph = inter.object;
	ret.t = inter.min;
	ret.object = inter.object;
	ret.point = ray_position(ray, ret.t);
	ret.eyev = neg_tuple(ray.direction);
	ret.norm = lig_normalize(*sph, ret.point);
	if (dot_product(ret.norm, ret.eyev) < 0)
	{
		ret.norm = neg_tuple(ret.norm);
		ret.inside = TRUE;
	}
	else
		ret.inside = FALSE;
	return (ret);
}

void	lig_print_computations(t_computations comp)
{
	printf("point ");
	lig_print_tuple(comp.point);
	printf("eyev ");
	lig_print_tuple(comp.eyev);
	printf("normal ");
	lig_print_tuple(comp.norm);
}

t_color	lig_color_at(t_minirt *rt_struct, t_ray ray)
{
	t_color			ret;
	t_computations		compt;
	t_sphere 		sph;
	t_obj_int	 ray_in_obj;

	ray_in_obj = ray_for_objects(rt_struct->word, ray);
	if (ray_in_obj.min != INT_MAX)
	{
		compt = lig_prepare_computations(ray_in_obj, ray);
		ret = lig_lighting(ray_in_obj.mat, rt_struct->luz,
				compt.point, compt.norm, compt.eyev);
	}
	else
		ret = c_new(1, 0, 0);
	return (ret);
}

t_matrix lig_view_transform(t_tuple form,t_tuple to , t_tuple up)
{
	t_tuple	forward;
	t_tuple	up_n;
	t_tuple	left;
	t_tuple	true_up;
	t_matrix mat;
	
	mat = mat_gener_identity(4);
	forward = normalize(sub_tuples(to, form));
	up_n = normalize(up);
	left = cross_product(forward, up_n);
	true_up = cross_product( forward,left);


	mat.matr[0][0] = left.x;
	mat.matr[0][1] = left.y;
	mat.matr[0][2] = left.z;

	mat.matr[1][0] = true_up.x;
	mat.matr[1][1] = true_up.y;
	mat.matr[1][2] = true_up.z;

	mat.matr[2][0] = -forward.x;
	mat.matr[2][1] = -forward.y;
	mat.matr[2][2] = -forward.z;


	mat = mat_multip( mat_gener_trans(-form.x, -form.y, -form.z),mat_cp(mat));
	return(mat);
}
