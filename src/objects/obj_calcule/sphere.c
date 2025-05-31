/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:26:38 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 11:50:06 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minRT.h"
#include "../objects.h"


t_sphere	sphere(t_point point_satrt, double ray_s)
{
	t_sphere	new;

	new.center = point_satrt;
	new.ray_s = ray_s;
	return (new);
}
