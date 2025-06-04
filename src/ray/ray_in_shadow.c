/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_in_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:08:23 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/12 17:28:56 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minRT.h"
#include <signal.h>
t_intersection ray_in_trinagles_s(t_object tri,int index,t_ray ray)
{
	int i;
	int i_;
	int min;
	t_intersection intr;
	t_intersection min_;
	t_triangle tria;
	
	i = -1;
	min = INT_MIN;
	min_.inter = 0;
	
	intr.t[0] = 0;
	while (++i < 12) {
		
		intr = ray_int_triangle(ray, tri.hit_box[i]);
		if(intr.t[0] > EPSILON)
		{
			i = 20;
			break;
		}
	
	}
	if(i == 20)
	{
	
		
	i = -1;
	while (++i < index)
	{

		intr = ray_int_triangle(ray, tri.triangle[i]);
		if(min == INT_MIN &&  intr.t[0] > EPSILON)
		{
			min = 0;
			min_ = intr;
			return (min_);

		}
		if( intr.t[0] > EPSILON &&  intr.t[0] < min_.t[0] )
		{
			min_ = intr;
			i_ = i;
			return (min_);
		}

	}
	return (min_);
	}	
	return (intr);
}


int	ray_for_shadow(t_list_ *objs_w, t_ray shadow_)
{
	t_intersection	shadow;
	t_object		*obj;
	t_triangle save;

	shadow.t[0] = -1;
	shadow.t[1] = -1;
	shadow.inter = -1;
	t_object  save_;


	while (objs_w != NULL)
	{
		obj = (t_object *)objs_w->content;
		if(obj->type == OBJ_SQUARE)
			save = obj->u_data.triangle;
		shadow = ray_int_object(shadow_,obj);

		if(obj->type == OBJ_SQUARE)
			obj->u_data.triangle = save ;


		if(shadow.t[0] > EPSILON && shadow.t[0]  < INT_MAX|| shadow.t[1] > EPSILON  && shadow.t[1] <INT_MAX)
		{
		 return (1);
		}

		if (objs_w->next == NULL)
			break ;
		objs_w = objs_w->next;
	}


	return (0);
}
