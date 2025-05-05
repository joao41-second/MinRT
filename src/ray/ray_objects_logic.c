/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:54:58 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/05 09:39:22 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"


t_obj_int ray_for_objects(t_list_ *objs_w,t_ray ray)
{
	t_obj_int save_points;
	t_intersection intr;
	t_object *obj;

	save_points.max = INT_MAX;
	save_points.min = INT_MAX;
	save_points.ints = NULL;

	save_points.object = objs_w->content;
	while (objs_w != NULL)
	{

		obj = (t_object *)objs_w->content;
		intr = ray_int_object(ray,*obj );
		if(intr.inter > 0)
		{
			if(intr.t[0] >= save_points.max || save_points.max == INT_MAX )
			{
				save_points.max = intr.t[0];
				save_points.object = intr.object;
				save_points.mat = intr.mat;
			}
			if(intr.t[1] >= save_points.max || save_points.max == INT_MAX )
			{
				save_points.object = intr.object;
				save_points.mat = intr.mat;	
				save_points.max = intr.t[1];
			}
			if(intr.t[0] <= save_points.min || save_points.max == INT_MAX )
			{
				save_points.min = intr.t[0];
				save_points.object = intr.object;
				save_points.mat = intr.mat;
			}
			if(intr.t[1] <= save_points.min || save_points.max == INT_MAX )
			{ 
				save_points.min = intr.t[1];

				save_points.object = intr.object;
				save_points.mat = intr.mat;
			}
		}
		if(objs_w->next == NULL)
			break;
		objs_w = objs_w->next;
	}
	return (save_points);
}

void ray_set_transform_obj(t_object *obj, t_matrix mat)
{
    if (obj->type == OBJ_SPHERE)
    {
        t_sphere *sphere = &obj->u_data.sphere;
		
        mat_free(&sphere->transform);
        mat_free(&sphere->inv_transform);
        mat_free(&sphere->inv_transpose);
        sphere->transform = mat_cp(mat);
        sphere->inv_transform = mat_cp(mat_inv(mat));
        sphere->inv_transpose = mat_cp(sphere->inv_transform);
        mat_trans(&sphere->inv_transpose);
        mat_not_neg_zero(&sphere->inv_transform);
        mat_not_neg_zero(&sphere->transform);
        mat_not_neg_zero(&sphere->inv_transpose);	
    }
    else if (obj->type == OBJ_PLANE)
    {
        t_plane *plane = &obj->u_data.plane;

        mat_free(&plane->transform);
        mat_free(&plane->inv_transform);
        mat_free(&plane->inv_transpose);

        plane->transform = mat_cp(mat);
        plane->inv_transform = mat_inv(mat);
        plane->inv_transpose = mat_cp(plane->inv_transform);
        mat_trans(&plane->inv_transpose);

        t_vector transformed_normal = mat_x_tuple(plane->normal, plane->inv_transpose);
        plane->normal = normalize(transformed_normal);
		mat_not_neg_zero(&plane->inv_transform);
        mat_not_neg_zero(&plane->transform);
        mat_not_neg_zero(&plane->inv_transpose);	
			printf("Plane transform applied:\n");
			mat_print(plane->transform);
			printf("Updated plane normal: (%f, %f, %f)\n", plane->normal.x, plane->normal.y, plane->normal.z);
    }
    else if (obj->type == OBJ_TRIANGLE)
	{
		t_triangle *triangle = &obj->u_data.triangle;

		mat_free(&triangle->transform);
		mat_free(&triangle->inv_transform);
		mat_free(&triangle->inv_transpose);
		triangle->transform = mat_cp(mat);
		triangle->inv_transform = mat_inv(mat);
		triangle->inv_transpose = mat_cp(triangle->inv_transform);
		mat_trans(&triangle->inv_transpose);
	}
	else
    {
        ft_printf("Error: Unknown obj type.\n");
        return;
    }
}


t_intersection ray_int_object(t_ray ray, t_object obj)
{
    t_intersection intersection;

    if (obj.type == OBJ_SPHERE)
    {
        intersection = ray_int_sphere(ray, obj.u_data.sphere);
		intersection.mat = obj.u_data.sphere.matiral;
		intersection.object = &obj; 
    }
    else if (obj.type == OBJ_PLANE)
    {
        intersection = ray_int_plane(ray, &obj.u_data.plane);
		intersection.mat = obj.u_data.plane.matiral;
		intersection.object = &obj; 
    }
	else if (obj.type == OBJ_TRIANGLE)
	{
		intersection = ray_int_triangle(ray, &obj.u_data.triangle);
		intersection.mat = obj.u_data.triangle.matiral;
		intersection.object = &obj; 
	}
    else
    {
        intersection.inter = 0;
        intersection.object = NULL;
        intersection.t[0] = -1;
        intersection.t[1] = -1;
    }

    return intersection;
}


