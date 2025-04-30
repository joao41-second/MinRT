/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:15:50 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/30 15:16:29 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ray.h"
#include "../minRT.h"
#include "ray_struct.h"

double mutl_dub(double nb1,double nb2)
{
	return (nb1*nb2);
}

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
	new  =  add_tuples( ray.origin,create_point(nb, nb, nb));
	if(nb == 0)
		return (new);
	return(create_point( ray.direction.x * new.x ,  ray.direction.y * new.y , ray.direction.z * new.z)); 
}

t_point ray_t_to_point(t_point const point,double t)
{
	t_point new;
	
	new = point;
	if(t*point.x != 0)
		new.x = point.x + (t);
	if(t*point.y != 0)
		new.y = point.y + (t);
	if(t*point.z != 0)
		new.z = point.z + (t);
	return (new);
}


double ray_model_venct(t_vector vect)
{
	double ret;	
	ret = sqrt(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z);
	return(ret);
}

t_tuple ray_ang_to_vect(double x,double y,double z)
{
	t_vector vect;
	double module_v;

	module_v = 1;
	vect.z = 1*cos(z);
	vect.x = 1*cos(x);
	vect.y = 1*cos(y);
	return(vect);
}



