/*                                                        :::      ::::::::   */
/*   rat_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/02 13:01:03 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "ray.h"
#include "ray_struct.h"


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

t_intersections ray_for_limts(t_lim_ran_int const limts,t_point point, t_list_ *word)
{
	t_intersections ret;
	double	add_z;
	double	add_x;
	double	add_y;
	t_obj_int test;

	ret.inter = NULL;
	ret.data = limts;
	if(limts.unit != 0)
	{
		add_z = limts.z.l_min;
		while (add_z < limts.z.l_max) 
		{
			add_y = limts.z.l_min;
			while (add_y < limts.z.l_max)
			{
				add_x = limts.z.l_min;
				while (add_x < limts.z.l_max)
				{
					test = ray_for_objects(word,ray_gener(point,ray_ang_to_vect(add_x, add_y, add_z)));
					ft_add_node(&test,&ret.inter);
					add_x +=limts.unit;
				}
				add_y +=limts.unit;
			}
			add_z +=limts.unit;
		}
	}
	return(ret);
}

