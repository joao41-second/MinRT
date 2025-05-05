/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tranform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:12:41 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 11:52:09 by jperpct          ###   ########.fr       */
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

void ray_set_transform_sph (t_object *sph,t_matrix mat)
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

void ray_set_transform_obj(t_object *obj, t_matrix mat)
{
    if (obj->type == OBJ_SPHERE)
    {
	ray_set_transform_sph(obj,mat );
    }
    else if (obj->type == OBJ_PLANE)
    {
    }
    else
    {
        ft_printf("Error: Unknown obj type.\n");
        return;
    }
}
