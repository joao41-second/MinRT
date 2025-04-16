/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:26:38 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/16 11:57:57 by rerodrig         ###   ########.fr       */
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
	new.matiral = obj_material_init(c_new(1.0,0.2,1.0), obj_init_values_material(0.5,0.9 , 0.9, 200));

	return (new);
}

void sph_update_mat (t_sphere *sph)
{
	sph->inv_transform = mat_inv(sph->transform);
	mat_free(&sph->inv_transpose);
	sph->inv_transpose = mat_cp(sph->inv_transform);
	mat_trans(&sph->inv_transpose);
	
}
