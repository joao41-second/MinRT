/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:34:08 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/22 09:42:36 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "../minRT.h"
#include "light_struct.h"
#include <math.h>
#include <stdio.h>

t_vector	lig_normalize(t_sphere sph, t_point p_the_obj)
{
	t_vector	ret;
	t_point		obj_point;
	t_point		obj_word;
	t_point		temp;

	obj_point = mat_x_tuple(p_the_obj, sph.inv_transform);

	obj_word = sub_tuples(obj_point, create_point(0, 0, 0));
	ret = mat_x_tuple(obj_word, sph.inv_transpose);	

	ret.w = 0;

	ret = normalize(create_vector(ret.x, ret.y, ret.z));
	return (ret);
}

t_color	lig_lighting(t_mater mat, t_light luz, t_computations comp)
{
	t_color	ret;
	t_color	efectiv;
	t_color	amb_c;
	t_tuple	luztv;
	double	t_luz_dot_normal;
	t_color	diffuse;
	t_color	sepcular;
	double	reflect_dot_eye;
	double	fact;
	
	efectiv = c_multipl(mat.color, luz.intenstiy);	


	luztv = normalize(sub_tuples(luz.point, comp.point));
	amb_c = c_scalar_multipl(efectiv, mat.values.amb);
	t_luz_dot_normal = dot_product( luztv,comp.norm);


		
	if(t_luz_dot_normal == -0)
		t_luz_dot_normal = 0;
	if (t_luz_dot_normal < 0)
	{
		diffuse = c_new(0, 0, 0);
		sepcular = c_new(0, 0, 0);
	}
	else
	{
		printf("sim \n");

		c_print(efectiv);
		printf("color diffuse tuple %f \n",mat.values.diffuse);

		printf("color luz normal %f \n",t_luz_dot_normal);

		diffuse = c_scalar_multipl(efectiv,mat.values.diffuse * t_luz_dot_normal);
		reflect_dot_eye = dot_product(lig_reflect(neg_tuple(luztv),comp.norm), comp.eyev);

		if (reflect_dot_eye <= 0)
			sepcular = c_new(0, 0, 0);
		else
		{
			fact = pow(reflect_dot_eye, mat.values.shininess);
			sepcular = c_scalar_multipl(luz.intenstiy,mat.values.specular* fact);
		}
	}
	
	ret = c_adding(sepcular, c_adding(diffuse, amb_c));
	printf("\n");
	c_print(sepcular);
	c_print(diffuse);
	c_print(amb_c);
	
	return (ret);
}

t_vector	lig_reflect(t_vector in, t_vector normal)
{
	t_vector	ret;

	ret = sub_tuples(in, scalar_mult_tuples(normal,
				2 * dot_product(in, normal)));
	return (ret);
}
