/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:13:28 by jperpct           #+#    #+#             */
/*   Updated: 2025/04/08 15:27:17 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../minRT.h"
#include <stdio.h>


void mouse(t_minirt *rt_struct)
{
	static t_point p1;
	static t_point p2;
	int x;
	int y;
	mlx_mouse_get_pos(rt_struct->canva.mlx, rt_struct->canva.mlx_wind, &x, &y);
	printf("x %d y %d \n",x,y);

}
