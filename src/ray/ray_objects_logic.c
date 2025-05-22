/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_objects_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:48:58 by rerodrig          #+#    #+#             */
/*   Updated: 2025/05/22 11:42:09 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "ray.h"
#include "ray_struct.h"
#include <stdio.h>

void	ray_organize(t_intersection intr, t_obj_int *save_points, t_object *obj)
{
	if (intr.t[0] - save_points->max > EPSILON || save_points->max == INT_MIN)
		save_points->max = intr.t[0];
	if (intr.t[1] - save_points->max > EPSILON || save_points->max == INT_MIN)
		save_points->max = intr.t[1];
	if (intr.t[0] - save_points->min < EPSILON || save_points->min == INT_MIN)
	{
		if (intr.t[0] > EPSILON)
		{
			save_points->min = intr.t[0];
			save_points->object = obj;
			save_points->mat = obj->matiral;
		}
	}
	if (intr.t[1] - save_points->min < EPSILON || save_points->min == INT_MIN)
	{
		if (intr.t[1] > EPSILON)
		{
			save_points->min = intr.t[1];
			save_points->object = obj;
			save_points->mat = obj->matiral;
		}
	}
}

static void	get_intersection(t_list_ *objs_w, t_ray ray, t_obj_int *save_points)
{
	t_object		*obj;
	t_intersection	intr;

	while (objs_w != NULL)
	{
		obj = (t_object *)objs_w->content;
		intr = ray_int_object(ray, *obj);
		if (intr.inter - 0 > EPSILON)
			ray_organize(intr, save_points, obj);
		if (objs_w->next == NULL)
			break ;
		objs_w = objs_w->next;
	}
}

t_obj_int	ray_for_objects(t_list_ *objs_w, t_ray ray, t_ray shadow_)
{
	t_obj_int	save_points;
	t_list_		*start;

	save_points.max = INT_MIN;
	save_points.min = INT_MIN;
	save_points.ints = NULL;
	save_points.object = objs_w->content;
	start = objs_w;
	get_intersection(objs_w, ray, &save_points);
	save_points.shadow = -1;
	if (save_points.min > 0)
	{
		shadow_.o = ray_position(ray, save_points.min);
		save_points.shadow = ray_for_shadow(start, shadow_);
	}
	return (save_points);
}

static t_intersection	handle_object_intersection(t_ray ray_, t_object obj)
{
	t_intersection	intersection;

	if (obj.type == OBJ_SPHERE)
		intersection = ray_int_sphere(ray_, obj.u_data.sphere);
	else if (obj.type == OBJ_PLANE)
		intersection = ray_int_plane(ray_, obj.u_data.plane);
	else if (obj.type == OBJ_TRIANGLE)
		intersection = ray_int_triangle(ray_, obj);
	else if (obj.type == OBJ_CYLINDER)
		intersection = ray_int_cylinder(ray_, obj.u_data.cylinder);
	else
	{
		intersection.inter = 0;
		intersection.object = NULL;
		intersection.t[0] = -1;
		intersection.t[1] = -1;
	}
	return (intersection);
}

t_intersection	ray_int_object(t_ray ray, t_object obj)
{
	t_intersection	intersection;
	t_ray			ray_;

	ray_ = ray_transform(ray, obj.inv_transform);
	intersection = handle_object_intersection(ray_, obj);
	intersection.mat = obj.matiral;
	if (obj.type == OBJ_TRIANGLE || obj.type == OBJ_CYLINDER)
		intersection.object = &obj;
	return (intersection);
}
