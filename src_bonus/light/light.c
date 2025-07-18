/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:34:08 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 18:12:14 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "../minRT.h"
#include "light_struct.h"
#include <math.h>
#include <stdio.h>
#include <curses.h>

t_vector	lig_reflect(t_vector in, t_vector normal)
{
	static t_vector	ret;

	ret = sub_tuples(in, scalar_mult_tuples(normal,
				2 * dot_product(in, normal)));
	return (ret);
}

t_color	lig_reflect_color(t_minirt *rt_struct, t_computations comp)
{
	t_object	*obj;
	t_ray		reflec;
	static t_color		color;
	static int	i = 0;
	t_point		point;

	obj = comp.object;
	i++;
	point = add_tuples(comp.point, scalar_mult_tuples(comp.norm, EPSILON));
	if (comp.object == NULL || obj == NULL || obj->matiral.reflect
		== 0 )
	{
		i = 0;
		return (c_new(0, 0, 0));
	}
	reflec = ray_gener(point, comp.reflect);
	color = lig_color_at(rt_struct, reflec);
	return (c_scalar_multipl(color, obj->matiral.reflect));
}

void	lig_set_color_patern(t_mater *mat, t_computations comp)
{
	t_color		c1;
	t_color		c2;

	if (c_chek_iqual_color(mat->pattern,
			c_new(-1, -1, -1)) == TRUE)
	{
		mat->color = mat->pattern;
		c1 = pat_stripe_at(comp.point, 'x', mat->pattern, mat->pattern_b);
		c2 = pat_stripe_at(comp.point, 'z', mat->pattern, mat->pattern_b);
		if (c_chek_iqual_color(c1, c2) == FALSE)
		{
			if (c_chek_iqual_color(mat->pattern, c2) == TRUE)
				mat->color = c2;
			else
				mat->color = mat->pattern_b;
		}
	}
}

void	lig_set_texture(t_object *test, t_obj_int *ray_in_obj,
	t_computations *compt)
{
	if (test->texture != NULL)
	{
		ray_in_obj->mat.color = pat_pixe_at(compt->textur_point,
				test->texture, &compt->uv);
		if (test->type == OBJ_SQUARE)
			ray_in_obj->mat.color = pat_pixe_at_triang(
					compt->textur_point, test->texture,
					&test->u_data.triangle, NULL);
	}
}

t_color	lig_loop_ligth(t_minirt *rt_struct, t_obj_int ray_in_obj,
		t_computations compt)
{
	t_color	ret;
	int		i;

	i = -1;
	ret = c_new(0, 0, 0);
	while (++i < rt_struct->luz_index + 1)
	{
		ret = c_adding(lig_lighting(ray_in_obj.mat,
					rt_struct->luz[i], compt),
				c_new(ret.red, ret.green, ret.blue));
	}
	return (ret);
}
