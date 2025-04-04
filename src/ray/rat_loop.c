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
#include <stdio.h>


t_obj_int ray_for_objects(t_list_ *objs_w,t_ray ray)
{
	t_obj_int save_points;
	t_intersection intr;
	t_sphere *conv;

	save_points.max = INT_MAX;
	save_points.min = INT_MAX;
	save_points.ints = NULL;
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
		}
		if(objs_w->next == NULL)
			break;
		objs_w = objs_w->next;
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

void ray_canva_loop_x(double pix_size,double y,t_minirt *rt_struct)
{
	double x_;
	double x;
	double y_;
	t_tuple use_the_memory;
	t_tuple sub;

	x = -1;
	y_ =( HALF - y) * pix_size  ;
	while(++x < WALL_X)
	{
		x_ = (-HALF +  x) * pix_size;
		use_the_memory = create_point(x_,y_, WALL_Z);
		sub = sub_tuples(use_the_memory,rt_struct->c_ray.direction);
		if(ray_for_objects(rt_struct->word,ray_gener(rt_struct->c_ray.origin,normalize(&sub))).min != INT_MAX)
		{
			canva_set_pixel(rt_struct, x, y, c_new(255.0, 1.0, 100.0));
		}
		else
		{
			canva_set_pixel(rt_struct, x, y, c_new(255.0, 255, 100.0));
		}
	}	
}


void ray_canva(t_point point, t_minirt *rt_struct)
{
	double pix_size;
	double y;
	t_tuple raiva;
	t_tuple sub;

	y = 0;
	pix_size = WALL_SIZE / WALL_X;
	while (y < WALL_Y) 
	{
		ray_canva_loop_x(pix_size, y, rt_struct);	
		y +=1;
	}
}


