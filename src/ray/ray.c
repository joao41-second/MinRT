/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:01:13 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/22 11:42:46 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

t_ray	ray_gener(t_point point, t_vector dir)
{
	t_ray	ray;

	ray.d = dir;
	ray.o = point;
	return (ray);
}

t_point	ray_position(t_ray ray, double t)
{
	t_point		scaled_direction;

	scaled_direction = scalar_mult_tuples(ray.d, t);
	return (add_tuples(ray.o, scaled_direction));
}

t_point	ray_t_to_point(t_point const point, double t)
{
	t_point	new;	

	new = point;
	if (t * point.x != 0)
		new.x = point.x + (t);
	if (t * point.y != 0)
		new.y = point.y + (t);
	if (t * point.z != 0)
		new.z = point.z + (t);
	return (new);
}

double	ray_model_venct(t_vector vect)
{
	double	ret;

	ret = sqrt(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z);
	return (ret);
}

t_tuple	ray_ang_to_vect(double x, double y, double z)
{
	t_vector	vect;

	vect.z = 1 * cos(z);
	vect.x = 1 * cos(x);
	vect.y = 1 * cos(y);
	return (vect);
}
