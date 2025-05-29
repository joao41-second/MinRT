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


int	ray_for_shadow(t_list_ *objs_w, t_ray shadow_)
{
	t_intersection	shadow;
	t_object		*obj;

	shadow.t[0] = -1;
	shadow.t[1] = -1;
	shadow.inter = -1;
	while (objs_w != NULL)
	{
		obj = (t_object *)objs_w->content;
		shadow = ray_int_object(shadow_,obj);
		if(shadow.t[0] > EPSILON || shadow.t[1] > EPSILON )
		{
		 return (1);
		}

		if (objs_w->next == NULL)
			break ;
		objs_w = objs_w->next;
	}
	return (0);
}
