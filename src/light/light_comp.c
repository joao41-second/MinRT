/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:08:21 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/08 20:56:15 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "light.h"

t_computations lig_prepare_computations( t_obj_int inter,t_ray ray)
{
	t_computations  ret;
	t_sphere 	*sph;

	sph  = inter.object;
	ret.t = inter.min;
	ret.object = inter.object;
	ret.point = ray_position(ray, ret.t);
	ret.eyev =  neg_tuple(ray.direction); //duvida do neg tuple
	ret.norm = lig_normalize(*sph, ret.point);
	if(dot_product(ret.norm, ret.eyev) < 0)
	{
		ret.norm = neg_tuple(ret.norm);
		ret.inside = TRUE;
	}
	else 
		ret.inside = FALSE;
	return(ret);
}

void lig_print_tuple(t_tuple tuple)
{
	if(tuple.w ==1)
	{
		printf( "point %f %f %f \n",tuple.x,tuple.y,tuple.z);
	}else
		printf( "vect %10.5f %f %f \n",tuple.x,tuple.y,tuple.z);

}

void lig_print_computations(t_computations comp)
{

	printf("point ");
	lig_print_tuple(comp.point);
	printf("eyev ");
	lig_print_tuple(comp.eyev);
	printf("normal ");
	lig_print_tuple(comp.norm);
}

t_color lig_color_at(t_minirt *rt_struct, t_ray ray)
{
	t_color ret;
	t_computations compt;;
	t_sphere sph;

	//printf("color mat %f %f %f \n",)
	
	if(ray_for_objects(rt_struct->word, ray).min != INT_MAX )
	{
		compt =  lig_prepare_computations(ray_for_objects(rt_struct->word, ray),ray); 
		lig_print_computations(compt);
		ret =  lig_lighting(sph.matiral,rt_struct->luz,compt.point,compt.norm,compt.eyev);
		printf (" the insied is %d\n",compt.inside );
	}
	else
		ret = c_new(0,0,0);
	return(ret);
}
