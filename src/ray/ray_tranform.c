/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tranform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:12:41 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/08 16:08:27 by rerodrig         ###   ########.fr       */
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
	sph->transform = mat_cp(mat);
	sph->inv_transform = mat_cp(mat_inv(mat));
}

void ray_set_transform_obj(t_object *obj, t_matrix mat)
{
    if (obj->type == OBJ_SPHERE)
    {
        t_sphere *sphere = &obj->u_data.sphere;
        mat_free(&sphere->transform);
        mat_free(&sphere->inv_transform);
        sphere->transform = mat_cp(mat);
        sphere->inv_transform = mat_cp(mat_inv(mat));
    }
    else if (obj->type == OBJ_PLANE)
    {
        t_plane *plane = &obj->u_data.plane;
        mat_free(&plane->transform);
        mat_free(&plane->inv_transform);
        plane->transform = mat_cp(mat);
        plane->inv_transform = mat_cp(mat_inv(mat));
    }
    else if (obj->type == OBJ_TRIANGLE)
    {
        t_triangle *triangle = &obj->u_data.triangle;
        mat_free(&triangle->transform);
        mat_free(&triangle->inv_transform);
        triangle->transform = mat_cp(mat);
        triangle->inv_transform = mat_cp(mat_inv(mat));
    }
    else
    {
        ft_printf("Error: Unknown obj type.\n");
        return;
    }
}