/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:11:18 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/25 18:15:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "../matrix/matrix.h"

typedef union s_ray
{
	struct
	{
		t_tuple origin;
		t_tuple direction;
	};
	t_tuple all[2];
} t_ray;


t_ray ray_gener(t_point point,t_vector dir);
t_point ray_position(t_ray ray,double nb);
	
#endif
