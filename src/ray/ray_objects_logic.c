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
#include "ray.h"
#include "ray_struct.h"
#include <stdio.h>
#include <strings.h>

void	ray_for_objects_organize(t_intersection intr, t_obj_int *save_points,t_object *obj)
{
	if (intr.t[0] - save_points->max  > EPSILON|| save_points->max == INT_MIN)
		save_points->max = intr.t[0];
	if (intr.t[1]- save_points->max > EPSILON || save_points->max == INT_MIN)
		save_points->max = intr.t[1];
	if (intr.t[0] -save_points->min < EPSILON || save_points->min == INT_MIN)
	{
		if(intr.t[0] > EPSILON)
		{
		save_points->min = intr.t[0];
		save_points->object = obj;
		save_points->mat = obj->matiral;
		save_points->ray = intr.ray_start;
		}
	}
	if (intr.t[1]-save_points->min < EPSILON || save_points->min == INT_MIN)
	{
		if(intr.t[1] > EPSILON)
		{
		save_points->min = intr.t[1];
		save_points->object = obj;
		save_points->mat = obj->matiral;

		save_points->ray = intr.ray_start;
		}
		}
	}


t_obj_int	ray_for_objects(t_list_ *objs_w, t_ray ray, t_ray shadow_)
{
	t_intersection	intr;
	t_intersection	shadow;
	t_obj_int		save_points;
	static t_tuple 		sh;
 	t_list_			*start;
	t_object		*obj;

	save_points.max = INT_MIN;
	save_points.min = INT_MIN;
	save_points.ints = NULL;
	save_points.object = objs_w->content;
	start = objs_w;

	while (objs_w != NULL)
	{
		obj = (t_object *)objs_w->content;
		intr = ray_int_object(ray,obj);
		if (intr.inter > EPSILON)
		{
			ray_for_objects_organize(intr, &save_points,obj);
		}
		if (objs_w->next == NULL)
			break ;
		objs_w = objs_w->next;
	}
	save_points.shadow = -1;
	if(save_points.min > 0)
	{;
		t_ray ok ;
		shadow_.origin =   ray_position(ray, save_points.min);
		save_points.shadow = ray_for_shadow(start, shadow_);
	}
	return (save_points);
}

t_intersection	ray_int_object(t_ray ray, t_object * obj)
{
	 t_intersection	intersection;
	static t_ray			ray_;
	intersection.inter = 0;
	ray_ = ray_transform(ray, obj->inv_transform);
	intersection.ray_start = ray_ ;
	if (obj->type == OBJ_SPHERE)
	{
		intersection = ray_int_sphere(ray_, obj->u_data.sphere);
		intersection.mat = obj->matiral;
	}
	else if (obj->type == OBJ_PLANE)
    	{
     	   intersection = ray_int_plane(ray_, obj->u_data.plane);
		intersection.mat = obj->matiral;
   	}
	else if (obj->type == OBJ_TRIANGLE)
	{
		intersection = ray_int_triangle(ray_, obj->u_data.triangle);
		intersection.mat = obj->matiral;
		intersection.object = &obj; 
	}
	else if (obj->type == OBJ_CYLINDER) {
		intersection = ray_int_cylinder(ray_, obj->u_data.cylinder);
		intersection.mat = obj->matiral;
		intersection.object = &obj;
	}else if (obj->type == OBJ_SQUARE) 
	{	
		intersection = ray_in_trinagles(obj, obj->index, ray_);
		intersection.mat = obj->matiral;
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
