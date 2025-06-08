/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:34:08 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 14:13:29 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "../minRT.h"
#include "light_struct.h"
#include <math.h>
#include <stdio.h>

t_vector	lig_reflect(t_vector in, t_vector normal)
{
	static t_vector	ret;

	ret = sub_tuples(in, scalar_mult_tuples(normal,
				2 * dot_product(in, normal)));
	return (ret);
}


t_color lig_reflect_color(t_minirt *rt_struct,t_computations comp)
{
	t_object *obj;
	t_ray reflec;
	t_color color;
	static int i = 0;

	obj = comp.object;

	i++;

	t_point point;
	point = add_tuples(comp.point,scalar_mult_tuples(comp.norm, EPSILON));
	
	if( comp.object == NULL || obj == NULL || obj->matiral.reflect == 0)
		return ((t_color){0,0,0});
	reflec = ray_gener(point, comp.reflect);
	color = lig_color_at(rt_struct, reflec);
	return (c_scalar_multipl(color,1));
	
}
