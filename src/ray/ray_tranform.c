/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tranform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:12:41 by jperpct           #+#    #+#             */
/*   Updated: 2025/06/10 13:32:28 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "ray.h"
#include "ray_struct.h"

t_ray	ray_transform(t_ray ray, t_matrix mat)
{
	t_ray	new_ray;

	new_ray = ray_gener(mat_x_tuple(ray.origin, mat),
			mat_x_tuple(ray.direction, mat));
	return (new_ray);
}

void	ray_set_transform_sph(t_object *sph, t_matrix mat)
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

void	ray_set_transform_pln(t_object *pln, t_matrix mat)
{
	t_vector	transformed_normal;

	mat_free(&pln->transform);
	mat_free(&pln->inv_transform);
	mat_free(&pln->inv_transpose);
	pln->transform = mat_cp(mat);
	pln->inv_transform = mat_inv(mat);
	pln->inv_transpose = mat_cp(pln->inv_transform);
	mat_trans(&pln->inv_transpose);
	transformed_normal = mat_x_tuple(pln->u_data.plane.normal,
			pln->inv_transpose);
	pln->u_data.plane.normal = normalize(transformed_normal);
	mat_not_neg_zero(&pln->inv_transform);
	mat_not_neg_zero(&pln->transform);
	mat_not_neg_zero(&pln->inv_transpose);
	mat_print(pln->transform);
}

void	ray_set_transform_obj(t_object *obj, t_matrix mat)
{
	if (obj->type == OBJ_SPHERE)
	{
		ray_set_transform_sph(obj, mat);
	}
	else if (obj->type == OBJ_PLANE)
	{
		ray_set_transform_pln(obj, mat);
	}
	else if (obj->type == OBJ_TRIANGLE || obj->type == OBJ_SQUARE)
	{
		obj->transform = mat_cp(mat);
		obj->inv_transform = mat_cp(mat_inv(mat));
	}
	else if (obj->type == OBJ_CYLINDER)
	{
		mat_free(&obj->transform);
		mat_free(&obj->inv_transform);
		obj->transform = mat_cp(mat);
		obj->inv_transform = mat_cp(mat_inv(mat));
	}
	else
	{
		printf("Unknown object type for transformation.\n");
	}
}
