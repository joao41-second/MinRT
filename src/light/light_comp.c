/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:08:21 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 02:46:00 by rerodrig         ###   ########.fr       */
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

// t_computations	lig_prepare_computations(t_obj_int inter, t_ray ray)
// {
// t_computations	ret;
// t_sphere	*sph;
// double test;

// sph = inter.object;
// ret.t = inter.min;
// if(inter.min >= 0)
// 	ret.t = 0;
// ret.object = inter.object;
// ret.point = ray_position(ray, ret.t);
// ret.eyev = neg_tuple(ray.direction);
// ret.norm = lig_normalize(*sph, ret.point);
// test = dot_product(ret.norm, ret.eyev);
// if(test == -0)
// 	test = 0;
// if (test < 0)
// {
// 	ret.norm = neg_tuple(ret.norm);
// 	ret.inside = TRUE;
// }
// else
// 	ret.inside = FALSE;
// return (ret);
// }
t_computations	lig_prepare_computations(t_obj_int inter, t_ray ray)
{
    t_computations	ret;
    t_object		*obj;
	double test;

    obj = inter.object;
    // fprintf(stdout, "Debug: Object type in lig_prepare_computations: %d\n", obj->type);
    ret.t = inter.min;
	if(inter.min >= 0)
		ret.t = 0;
    ret.object = inter.object;
    ret.point = ray_position(ray, ret.t);
    ret.eyev = neg_tuple(ray.direction);
    if (obj->type == OBJ_SPHERE)
    {
        ret.norm = lig_normalize_obj(*obj, ret.point);
    }
    else if (obj->type == OBJ_PLANE)
    {
        ret.norm = obj->u_data.plane.base_normal;
    }
    else if (obj->type == OBJ_TRIANGLE)
	{
		t_triangle *triangle = &obj->u_data.triangle;
		ret.norm = triangle->normal;
	}
    else
    {
        // fprintf(stderr, "Error: Unknown object type (%d) in lig_prepare_computations\n", obj->type);
        ret.norm = create_vector(0, 0, 0);
    }
	test = dot_product(ret.norm, ret.eyev);
	if(test == -0)
		test = 0;
	if (test < 0)
	{
		ret.norm = neg_tuple(ret.norm);
		ret.inside = TRUE;
	}
	else
		ret.inside = FALSE;

    return (ret);
}




t_color lig_shade_hit(t_obj_int obj,t_light luz,t_computations comp)
{
	t_color ret;	
	ret = lig_lighting(obj.mat,luz,comp);
	return(ret);
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
	t_obj_int	 ray_in_obj;

	ret = c_new(0, 0, 0);
	ray_in_obj = ray_for_objects(rt_struct->word, ray);
	if (ray_in_obj.min < 0){
		compt = lig_prepare_computations(ray_in_obj, ray);
		ret = lig_lighting(ray_in_obj.mat, rt_struct->luz,compt);
	}
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
	
	left = cross_product( forward,up_n);

	true_up = cross_product(left,forward);
	
	mat.matr[0][0] = left.x;
	mat.matr[0][1] = left.y;
	mat.matr[0][2] = left.z;

	mat.matr[1][0] = true_up.x;
	mat.matr[1][1] = true_up.y;
	mat.matr[1][2] = true_up.z;

	mat.matr[2][0] = -forward.x;
	mat.matr[2][1] = -forward.y;
	mat.matr[2][2] = -forward.z;

	mat = mat_multip( mat_cp(mat),mat_gener_trans(-form.x, -form.y, -form.z));
	return(mat);
}
