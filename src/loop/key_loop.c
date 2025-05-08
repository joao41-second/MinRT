/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:32:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/05/06 14:06:39 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minRT.h"

void muve_cam(int ket,t_minirt *rt_struct)
{
	if(ket == KEY_W )
	{
		rt_struct->point.x += 0.1;
	}
	if(ket == KEY_S )
	{
		rt_struct->point.x -= 0.1;
	}
}

void	key_loop(int key, t_minirt *rt_struct)
{
	(void)key;
	(void)rt_struct;
	if (key == KEY_ESC)
	{
		mlx_loop_end(rt_struct->canva.mlx);
	}
	if (key == KEY_O)
	{
		rt_struct->luz.point.x+=0.1;
	}
	if (key == KEY_L)
	{
		rt_struct->luz.point.x-=0.1;
	}


}
