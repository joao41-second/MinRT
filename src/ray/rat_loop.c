/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rat_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/02 11:47:30 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "ray.h"
#include "ray_struct.h"
#include <stdio.h>
#include <stdlib.h>


t_obj_int ray_for_objects(t_list_ *objs_w,t_ray ray)
{
	t_obj_int save_points;
	t_intersection intr;
	t_sphere *conv;

	save_points.max = INT_MAX;
	save_points.min = INT_MAX;
	save_points.ints = NULL;
	objs_w = ft_node_start(objs_w);	
	while (objs_w != NULL)
	{
		conv = (t_sphere *)objs_w->content;
		intr = ray_int_sphere(ray,*conv );
		if(intr.inter > 0)
		{
			if(intr.t[0] > save_points.max || save_points.max == INT_MAX )
				save_points.max = intr.t[0];
			if(intr.t[1] > save_points.max || save_points.max == INT_MAX )
				save_points.max = intr.t[1];
			if(intr.t[0] < save_points.min || save_points.max == INT_MAX )
				save_points.min = intr.t[0];
			if(intr.t[1] < save_points.min || save_points.max == INT_MAX )
				save_points.min = intr.t[1];
			ft_add_node(&intr,& save_points.ints);
		}	
		objs_w= objs_w->next;
	}
	return (save_points);
}

t_intersections ray_for_limts(t_lim_ran_int const limts,t_point s_point)
{
	t_intersections ret;
	
	
	return(ret);
}

