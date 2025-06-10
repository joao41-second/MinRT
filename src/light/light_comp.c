/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:08:21 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/04 14:33:04 by jperpct          ###   ########.fr       */
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
	t_computations		ret;
	static float		test = 0;
	static t_ray		ray_;
	t_object			*obj;

	obj = inter.object;
	ray_ = ray_transform(ray, obj->inv_transform);
	ret.t = inter.min;
	ret.uv.v = -1;
	ret.uv.u = -1;
	ret.object = inter.object;
	ret.point = ray_position(ray, ret.t);
	ret.textur_point = ray_position(ray_, ret.t);
	ret.eyev = neg_tuple(ray.direction);
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
	ret.reflect = lig_reflect(ray.direction, ret.norm);
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

t_color	shadow_calcule(t_obj_int save_points, int index, t_light *shadow_,
                       t_ray ray, t_list_ *word)
{
	int				i;
	t_ray			rat;
	t_color			color;
	t_computations	comp;

	color = c_new(0, 0, 0);
	if (save_points.min > 0)
	{
		i = -1;
		while (++i <= index)
		{
			rat.origin = ray_position(ray, save_points.min);
			rat.direction = shadow_[i].point;
			save_points.shadow = ray_for_shadow(word, rat, save_points.object);
			comp = lig_prepare_computations(save_points, rat);
			if (save_points.shadow == 1)
			{
				color = c_adding(c_new(color.red, color.green, color.blue),
						lig_lighting(save_points.mat, shadow_[i], comp));
			}
		}
	}
	return (color);
}

t_color	lig_color_at(t_minirt *rt_struct, t_ray ray)
{
	t_computations	compt;
	t_obj_int		ray_in_obj;
	t_color			ret;
	t_ray			luz;
	t_object		*test;
	int			i;
	t_color			tes;

	ret = c_new(0, 0, 0);
	ray_in_obj = ray_for_objects(rt_struct->word, ray, luz);
	if (ray_in_obj.min > EPSILON)
	{
		compt = lig_prepare_computations(ray_in_obj, ray_in_obj.ray);
		test = ray_in_obj.object;
		if (test->texture != NULL)
		{
			ray_in_obj.mat.color = pat_pixe_at(compt.textur_point,
					test->texture, &compt.uv);
			if (test->type == OBJ_SQUARE)
				ray_in_obj.mat.color = pat_pixe_at_triang(
						compt.textur_point, test->texture,
						&test->u_data.triangle, NULL);
			if (compt.uv.v != -1)
				compt.norm = pat_nomral_preturb(compt.uv, compt.norm,
						test->texture, 1);
		}
		i = -1;
		tes = shadow_calcule(ray_in_obj, rt_struct->luz_index,
				rt_struct->luz, ray, rt_struct->word);
		ret = c_subtracting(c_new(ret.red, ret.green, ret.blue), tes);
		compt.t_luz = -2;
		while (++i < rt_struct->luz_index + 1)
		{
			ret = c_adding(lig_lighting(ray_in_obj.mat,
						rt_struct->luz[i], compt),
					c_new(ret.red, ret.green, ret.blue));
		}
		ret = c_adding(c_new(ret.red, ret.green, ret.blue),
				lig_reflect_color(rt_struct, compt));
	}
	return (ret);
}
