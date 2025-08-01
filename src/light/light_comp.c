/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:08:21 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/18 09:31:14 by rerodrig         ###   ########.fr       */
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
	t_object		*obj;
	double			test;

	obj = inter.object;
	ret.t = inter.min;
	ret.object = inter.object;
	ret.point = ray_position(ray, ret.t);
	ret.eyev = neg_tuple(ray.d);
	ret.norm = lig_normalize(*obj, ret.point);
	test = dot_product(ret.norm, ret.eyev);
	ret.t_luz = inter.shadow;
	if (test < EPSILON)
	{
		ret.norm = neg_tuple(ret.norm);
		ret.inside = TRUE;
	}
	else
		ret.inside = FALSE;
	return (ret);
}

t_color	lig_shade_hit(t_obj_int obj, t_light luz, t_computations comp)
{
	t_color	ret;

	ret = lig_lighting(obj.mat, luz, comp);
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
	t_computations		compt;
	t_obj_int			ray_in_obj;
	t_color				ret;
	t_ray				luz;

	ret = c_new(0, 0, 0);
	luz.o = ray.o;
	luz.d = normalize(rt_struct->luz.point);
	ray_in_obj = ray_for_objects(rt_struct->word, ray, luz);
	if (ray_in_obj.min > EPSILON)
	{
		compt = lig_prepare_computations(ray_in_obj, ray);
		ret = lig_lighting(ray_in_obj.mat, rt_struct->luz, compt);
	}
	return (ret);
}
