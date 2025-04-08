/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:08:21 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/08 19:24:22 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "light.h"

t_computations prepare_computations( t_obj_int inter,t_ray ray)
{
	t_computations  ret;
	t_sphere 	*sph;

	sph  = inter.object;
	ret.t = inter.min;
	ret.object = inter.object;
	ret.point = ray_position(ray, ret.t);
	ret.eyev =  neg_tuple(ray.direction);
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
