/* ************************************************************************** *//*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:15:50 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/25 18:18:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

t_ray ray_gener(t_point point,t_vector dir)
{
	t_ray ray;
	ray.direction = dir;
	ray.origin = point;
	return (ray);
}

t_point ray_position(t_ray ray,double nb)
{
	t_point new;
	new  = add_tuples(ray.origin, ray.direction);
	if(nb == 0)
		return (new);
	return(scalar_mult_tuples(new, nb)); 
}
