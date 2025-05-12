/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tranform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:12:41 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/12 14:41:11 by rerodrig         ###   ########.fr       */
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
void ray_set_transform_pln(t_object *pln, t_matrix mat)
{
    mat_free(&pln->transform);
    mat_free(&pln->inv_transform);
    mat_free(&pln->inv_transpose);

    pln->transform = mat_cp(mat);
    pln->inv_transform = mat_inv(mat);
    pln->inv_transpose = mat_cp(pln->inv_transform);
    mat_trans(&pln->inv_transpose);

    mat_not_neg_zero(&pln->inv_transform);
    mat_not_neg_zero(&pln->transform);
    mat_not_neg_zero(&pln->inv_transpose);
    
    t_vector base_normal = create_vector(0, 1, 0);
    pln->u_data.plane.normal = mat_x_tuple(base_normal, pln->inv_transpose);
    pln->u_data.plane.center = mat_x_tuple(create_point(0, 0, 0), pln->transform);

	
    
    printf("Plane transform applied:\n");
    mat_print(pln->transform);
    printf("Updated plane normal: (%f, %f, %f)\n", 
           pln->u_data.plane.normal.x, pln->u_data.plane.normal.y, pln->u_data.plane.normal.z);
    printf("Updated plane center: (%f, %f, %f)\n", 
           pln->u_data.plane.center.x, pln->u_data.plane.center.y, pln->u_data.plane.center.z);
}
void	ray_set_transform_tri(t_object *tri, t_matrix mat)
{
	mat_free(&tri->transform);
	mat_free(&tri->inv_transform);
	mat_free(&tri->inv_transpose);

	tri->transform = mat_cp(mat);
	tri->inv_transform = mat_cp(mat_inv(mat));
	tri->inv_transpose = mat_cp(tri->inv_transform);
	mat_trans(&tri->inv_transpose);
	mat_not_neg_zero(&tri->inv_transform);
	mat_not_neg_zero(&tri->transform);
	mat_not_neg_zero(&tri->inv_transpose);
}
void	ray_set_transform_cyl(t_object *cyl, t_matrix mat)
{
	mat_free(&cyl->transform);
	mat_free(&cyl->inv_transform);
	mat_free(&cyl->inv_transpose);

	cyl->transform = mat_cp(mat);
	cyl->inv_transform = mat_cp(mat_inv(mat));
	cyl->inv_transpose = mat_cp(cyl->inv_transform);
	mat_trans(&cyl->inv_transpose);
	mat_not_neg_zero(&cyl->inv_transform);
	mat_not_neg_zero(&cyl->transform);
	mat_not_neg_zero(&cyl->inv_transpose);
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
	else if (obj->type == OBJ_TRIANGLE)
    {
        mat_free(&obj->transform);
        mat_free(&obj->inv_transform);
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
