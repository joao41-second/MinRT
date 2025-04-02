/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_limit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:32:55 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/02 11:42:25 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "ray_struct.h"


t_lim_ran_int ray_inc_lim_ray(t_limit x,t_limit y, t_limit z,double unit)
{
	t_lim_ran_int ret;
	
	ret.z = z;
	ret.x = x;
	ret.y = y;
	ret.unit = unit;
	return(ret);
}

t_limit ray_limit_inic(double max, double min)
{
	t_limit ret;

	ret.l_max = max;
	ret.l_min = min;
	return (ret);
}
