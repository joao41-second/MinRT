/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_in_objects_and_word.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:54:58 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/30 15:08:31 by jperpct          ###   ########.fr       */
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
			if(intr.t[0] > save_points.max || save_points.max == INT_MAX )
			{
				save_points.max = intr.t[0];
				save_points.object = intr.object;
				save_points.mat = intr.mat;
			}
			if(intr.t[1] > save_points.max || save_points.max == INT_MAX )
			{
				save_points.object = intr.object;
				save_points.mat = intr.mat;	
				save_points.max = intr.t[1];
			}
			if(intr.t[0] < save_points.min || save_points.max == INT_MAX )
			{
				save_points.min = intr.t[0];
				save_points.object = intr.object;
				save_points.mat = intr.mat;
			}
			if(intr.t[1] < save_points.min || save_points.max == INT_MAX )
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
    }
    else if (obj.type == OBJ_PLANE)
    {
        intersection = ray_int_plane(ray, &obj);

	intersection.mat = obj.u_data.sphere.matiral;
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


