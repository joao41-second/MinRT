/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:43:55 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/13 20:33:59 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "light_struct.h"
#include <stdio.h>

void	lig_specular_and_difuse(t_lightnig *light,
		t_computations comp, t_mater mat, t_light luz)
{
	light->diffuse = c_scalar_multipl(light->efectiv,
			mat.values.diffuse * light->t_luz_dot_normal);
	light->reflect_dot_eye = dot_product(lig_reflect
			(neg_tuple(light->luztv), comp.norm), comp.eyev);
	if (light->reflect_dot_eye <= EPSILON)
		light->sepcular = c_new(0, 0, 0);
	else
	{
		light->fact = pow(light->reflect_dot_eye, mat.values.shininess);
		light->sepcular = c_scalar_multipl(luz.intenstiy,
				mat.values.specular * light->fact);
	}
}

t_color	lig_lighting(t_mater mat, t_light luz, t_computations comp)
{
	t_lightnig	light;

	light.efectiv = c_multipl(mat.color, luz.intenstiy);
	light.luztv = normalize(sub_tuples(luz.point, comp.point));
	light.amb_c = c_multipl(light.efectiv, c_new(mat.values.amb,
				mat.values.amb, mat.values.amb));
	light.t_luz_dot_normal = dot_product(normalize(light.luztv), comp.norm);
	if (light.t_luz_dot_normal < EPSILON)
	{
		light.diffuse = c_new(0, 0, 0);
		light.sepcular = c_new(0, 0, 0);
	}
	else
		lig_specular_and_difuse(&light, comp, mat, luz);
	if(comp.t_luz == 1)
	{
		//light.diffuse = c_new(0, 0, 0);
		//light.sepcular = c_new(0, 0, 0);
	}
	light.ret = c_adding(c_adding(light.sepcular, light.amb_c), light.diffuse);
	return (light.ret);
}
