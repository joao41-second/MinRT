/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tranform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:12:41 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/30 15:04:28 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "ray.h"
#include "ray_struct.h"


t_ray ray_transform(t_ray ray,t_matrix mat)
{
	t_ray new_ray;
	new_ray = ray_gener(mat_x_tuple(ray.origin, mat), mat_x_tuple(ray.direction, mat) );
	return(new_ray);
}

void ray_set_transform (t_sphere *sph,t_matrix mat)
{
	mat_free(&sph->transform);
	mat_free(&sph->inv_transform);
	mat_free(&sph->inv_transpose);
	sph->transform = mat_cp(mat);
	sph->inv_transform = mat_cp(mat_inv(mat));
	sph->inv_transpose = mat_cp(sph->inv_transform);
	mat_trans(&sph->inv_transpose);

	mat_not_neg_zero(&sph->inv_transform);
	mat_not_neg_zero(&sph->transform);
	mat_not_neg_zero(&sph->inv_transpose);	
}


