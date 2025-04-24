/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:41:36 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/23 16:44:37 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"
#include "canvas_struct.h"


int c_chek_iqual_color(t_color a , t_color b)
{
	int i;
	i = 0;
	if(fabs(a.color[i] - b.color[i]) < EPSILON)
	{
		i++;
		if(fabs(a.color[i] - b.color[i]) < EPSILON)
		{
			i++;;
			if(fabs(a.color[i] - b.color[i]) < EPSILON )
				return (TRUE);
		}
	}
	return  (FALSE);
}

void c_print(t_color color)
{
	 printf("color %f %f %f \n",color.red,color.blue,color.green);
}
