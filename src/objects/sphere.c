/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:26:38 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/03 12:44:53 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "objects.h"



t_sphere sphere(t_point point_satrt , double ray_s)
{
	t_sphere new;

	new.center = point_satrt;
	new.ray_s = ray_s;
	new.transform = mat_gener(4);
	new.inv_transform = mat_gener(4);
	new.inv_transpose = mat_gener(4);

	return (new);
}

void sph_update_mat (t_sphere *sph)
{
	sph->inv_transform = mat_inv(sph->transform);
	mat_free(&sph->inv_transpose);
	sph->inv_transpose = mat_cp(sph->inv_transform);
	mat_trans(&sph->inv_transpose);
	
}
