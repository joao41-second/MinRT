/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:54:58 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/07 11:48:58 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "ray_struct.h"

void	ray_for_objects_organize(t_intersection intr, t_obj_int *save_points,t_object *obj)
{
	if (intr.t[0] >= save_points->max || save_points->max == INT_MIN)
		save_points->max = intr.t[0];
	if (intr.t[1] >= save_points->max || save_points->max == INT_MIN)
		save_points->max = intr.t[1];
	if (intr.t[0] <= save_points->min || save_points->min == INT_MIN)
	{
		save_points->min = intr.t[0];
		save_points->object = obj;
		save_points->mat = obj->matiral;
	}
	if (intr.t[1] <= save_points->min || save_points->min == INT_MIN)
	{
		save_points->min = intr.t[1];
		save_points->object = obj;
		save_points->mat = obj->matiral;
	}
	}


t_obj_int	ray_for_objects(t_list_ *objs_w, t_ray ray, t_ray shadow_)
{
	t_intersection	intr;
	t_intersection	shadow;
	t_obj_int		save_points;
	t_object		*obj;

	save_points.max = INT_MIN;
	save_points.min = INT_MIN;
	save_points.shadow = -1;
	save_points.ints = NULL;
	save_points.object = objs_w->content;
	while (objs_w != NULL)
	{
		obj = (t_object *)objs_w->content;
		intr = ray_int_object(ray,*obj);
		shadow = ray_int_object(shadow_,*obj);
		if (intr.inter > 0)
		{
			ray_for_objects_organize(intr, &save_points,obj);

		}
		if (objs_w->next == NULL)
			break ;
		objs_w = objs_w->next;
	}
	save_points.shadow = shadow.inter;
	return (save_points);
}

t_intersection	ray_int_object(t_ray ray, t_object obj)
{
	t_intersection	intersection;
	t_ray			ray_;

	ray_ = ray_transform(ray, obj.inv_transform);
	if (obj.type == OBJ_SPHERE)
	{
		intersection = ray_int_sphere(ray_, obj.u_data.sphere);
		intersection.mat = obj.matiral;
	}
	else if (obj.type == OBJ_PLANE)
    {
     	   intersection = ray_int_plane(ray, obj.u_data.plane);
		intersection.mat = obj.matiral;
    }
	else if (obj.type == OBJ_TRIANGLE)
	{
		intersection = ray_int_triangle(ray, obj);
		intersection.mat = obj.matiral;
		intersection.object = &obj; 
	}
	else if (obj.type == OBJ_CYLINDER) {
		intersection = ray_int_cylinder(ray_, obj.u_data.cylinder);
		intersection.mat = obj.matiral;
		intersection.object = &obj;
	}
	else
	{
		intersection.inter = 0;
		intersection.object = NULL;
		intersection.t[0] = -1;
		intersection.t[1] = -1;
	}
	return (intersection);
}
