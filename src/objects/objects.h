/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:05:57 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/01 14:58:24 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
#define OBJECTS_H

#include "../miniRT_struct.h"
typedef struct s_sphere 
{
	double	ray_s;
	t_point center;
		
}	t_sphere;

t_sphere sphere(t_point point_satrt , double ray_s);

#endif
